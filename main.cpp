#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <vector>
#include "createBase.h"



int main() {
    //getGroups();
    //getAuditory();
    std::vector<Auditory> myAuditoryBase; // Объявление переменной
    createAuditoryBase(myAuditoryBase);
    return 0;
}