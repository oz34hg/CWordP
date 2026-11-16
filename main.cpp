#include <iostream>
#include <thread>
#include <chrono>


int main() {
    std::string sentence = "qwertyuioopasdfghjklzxcvbnm1234567890";


    for (int i = 0; i < 500; i++) {
        for (char c : sentence) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }

        std::cout<<std::endl;
    }



    return 0;
}