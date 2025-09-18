#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    
    std::ofstream outputFile("timestamp.txt", std::ios::app);
    
    if (outputFile.is_open()) {
        outputFile << "当前时间: " << std::put_time(std::localtime(&current_time), "%Y-%m-%d %H:%M:%S") << std::endl;
        outputFile.close();
        std::cout << "时间已成功写入文件" << std::endl;
    } else {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }
    
    return 0;
}