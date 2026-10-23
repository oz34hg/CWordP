#!/bin/bash
set -e

export DEBIAN_FRONTEND=noninteractive

echo "=== 1. Cleaning up existing sessions ==="
pkill -f vncserver || true
pkill -f websockify || true
rm -rf /tmp/.X11-unix/X1 /tmp/.X1-lock ~/.vnc/*.pid ~/.vnc/*.log || true

echo "=== 2. Installing Desktop Environment & Tools ==="
sudo apt-get update -qq
sudo apt-get install -y -qq openbox tigervnc-standalone-server novnc websockify xterm dbus-x11

echo "=== 3. Setting up VNC Startup Config ==="
mkdir -p ~/.vnc

cat << 'xEOF' > ~/.vnc/xstartup
#!/bin/sh
unset SESSION_MANAGER
unset DBUS_SESSION_BUS_ADDRESS
export DISPLAY=:1
xterm -geometry 80x24+10+10 -ls -title "$VNCDESIGNATION Desktop" &
exec openbox-session
xEOF

chmod +x ~/.vnc/xstartup

echo "=== 4. Starting VNC Server (Port 5901) ==="
tigervncserver :1 -geometry 1280x720 -depth 16 -SecurityTypes None --I-KNOW-THIS-IS-INSECURE -localhost no

echo "=== 5. Starting noVNC Proxy (Port 6080) ==="
nohup websockify --web=/usr/share/novnc/ 6080 localhost:5901 > /tmp/novnc.log 2>&1 &

sleep 2

echo "=== Verification ==="
if ss -tuln | grep -q ':6080'; then
    echo "SUCCESS: noVNC is running on port 6080!"
else
    echo "ERROR: Check /tmp/novnc.log or ~/.vnc/*.log"
fi
