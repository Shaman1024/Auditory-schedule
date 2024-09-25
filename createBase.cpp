//
// Created by vanya on 20.09.2024.
//

#include <string>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <vector>
#include "createBase.h"
#include "nlohmann/json.hpp"

size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *s) {
    size_t newLength = size * nmemb;
    s->append((char *)contents, newLength);
    return newLength;
}
void getGroups(){
    std::string url = "https://iis.bsuir.by/api/v1/student-groups"; // URL, который отдает JSON
    std::string filename = "groupList.json";

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "UTF-8");

        std::string response_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Получение заголовка Content-Type (опционально)
            char *content_type = NULL;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);

            // Проверка, является ли Content-Type JSON (опционально)
            if (content_type != NULL && strstr(content_type, "application/json") != NULL) {
                std::ofstream outputFile(filename);
                if (outputFile.is_open()) {
                    outputFile << response_string;
                    outputFile.close();
                    std::cout << "Succes " << filename << std::endl;
                } else {
                    std::cerr << "Ошибка при открытии файла " << filename << " для записи" << std::endl;
                }
            } else {
                std::cerr << "Ошибка: сервер не отдал JSON файл" << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }
};

void getAuditory(){
    std::string url = "https://iis.bsuir.by/api/v1/auditories"; // URL, который отдает JSON
    std::string filename = "audienceList.json";

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "UTF-8");

        std::string response_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Получение заголовка Content-Type (опционально)
            char *content_type = NULL;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);

            // Проверка, является ли Content-Type JSON (опционально)
            if (content_type != NULL && strstr(content_type, "application/json") != NULL) {
                std::ofstream outputFile(filename);
                if (outputFile.is_open()) {
                    outputFile << response_string;
                    outputFile.close();
                    std::cout << "Succes " << filename << std::endl;
                } else {
                    std::cerr << "Ошибка при открытии файла " << filename << " для записи" << std::endl;
                }
            } else {
                std::cerr << "Ошибка: сервер не отдал JSON файл" << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }
};

void getGroupSchedule(std::string groupId){
    std::string url = "https://iis.bsuir.by/api/v1/schedule?studentGroup=" + groupId; // URL, который отдает JSON
    std::string filename = groupId + ".json";

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "UTF-8");

        std::string response_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Получение заголовка Content-Type (опционально)
            char *content_type = NULL;
            curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &content_type);

            // Проверка, является ли Content-Type JSON (опционально)

        }

        curl_easy_cleanup(curl);
    }
};

void createAuditoryBase(std::vector<Auditory> dataArr){
    using json = nlohmann::json;
    std::ifstream file("grouplist.json");
    json data; //чё?
    file >> data;
    for (const auto& item : data) {
        std::string dataname = item["name"];
        dataArr.push_back(Auditory(dataname, {}));

    }
};