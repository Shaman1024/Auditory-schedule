//
// Created by vanya on 20.09.2024.
//

#ifndef COURSEWORK_CREATEBASE_H
#define COURSEWORK_CREATEBASE_H

struct Lesson {
    std::string groupNumber;
    std::string subjectName;
    std::string startTime;
    std::string lecturer;
};

class Auditory {
public:
    Auditory(const std::string& number, const std::vector<Lesson>& schedule)
            : number_(number), schedule_(schedule) {}

    std::string getNumber() const { return number_; }
    const std::vector<Lesson>& getSchedule() const { return schedule_; }

private:
    std::string number_;
    std::vector<Lesson> schedule_;
};
void getGroups();
void getAuditory();
void getGroupSchedule(std::string groupId);
void createAuditoryBase(std::vector<Auditory> dataArr);

#endif //COURSEWORK_CREATEBASE_H
