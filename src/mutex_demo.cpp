#include<chrono>
#include<iostream>
#include<map>
#include<mutex>
#include<thread>

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;

void save_page(const std::string url)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::lock_guard<std::mutex> guard{g_pages_mutex};
    g_pages[url] = "Fake content";
}

int main(int argc, char** argv)
{
    std::thread t1{save_page, "https://foo.com"};
    std::thread t2{save_page, "https://bar.com"};

    t1.join();
    t2.join();

    for(const auto& pair: g_pages)
    {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }
}