#include <bits/stdc++.h>
using namespace std;
class Lab
{
private:
    string labName;
    int capacity;

public:
    Lab(string s, int n) : labName(s), capacity(n) {}
    //getter
    string getLabName(void)
    {
        return labName;
    }
    int getCapacity(void)
    {
        return capacity;
    }
    //setter
    void setLabName(string s)
    {
        labName = s;
    }
    void setCapacity(int n)
    {
        capacity = n;
    }

    void show(void)
    {
        cout << "Lab Name: " << getLabName() << " Capacity: " << getCapacity() << endl;
    }
};
class LecturerRoom
{
private:
    string roomName;
    int roomNo;
    int capacity;

public:
    LecturerRoom(string s, int no, int cap) : roomName(s), roomNo(no), capacity(cap) {}
    //getter
    string getRoomName(void)
    {
        return roomName;
    }
    int getRoomNo(void)
    {
        return roomNo;
    }
    int getCapacity(void)
    {
        return capacity;
    }
    //setter
    void setRoomName(string s)
    {
        roomName = s;
    }
    void setRoomNo(int n)
    {
        roomNo = n;
    }
    void setCapacity(int n)
    {
        capacity = n;
    }

    void show(void)
    {
        cout << "Name: " << getRoomName() << " Room no: " << getRoomNo() << " Capacity: " << getCapacity() << endl;
    }
};

class Building
{
private:
    vector<Lab> lab;
    vector<LecturerRoom> lecRoom;

public:
    Building()
    {
        cout << "Welcome to Bulding!" << endl;
    }
    void setLab(string labN, int LabCap)
    {
        Lab temp = Lab(labN, LabCap);
        lab.push_back(temp);
    }
    void setRoom(string RoName, int RomNo, int RoCap)
    {
        LecturerRoom temp = LecturerRoom(RoName, RomNo, RoCap);
        lecRoom.push_back(temp);
    }
    void showAllLabs(void)
    {
        cout << "Show all labs: " << endl;
        for (int i = 0; i < lab.size(); i++)
            lab[i].show();
        cout << endl;
    }
    void showAllLecturerRoom(void)
    {
        cout << "Show all lecturer's room: " << endl;
        for (int i = 0; i < lecRoom.size(); i++)
            lecRoom[i].show();
        cout << endl;
    }
};
int main(void)
{
    Building build1;
    build1.setLab("mpk1", 30);
    build1.setLab("mpk2", 40);
    build1.setLab("mpk3", 50);
    build1.showAllLabs();
    build1.setRoom("Hafiz", 102, 3);
    build1.setRoom("Aishah", 105, 4);
    build1.setRoom("Alam", 109, 4);
    build1.showAllLecturerRoom();
}