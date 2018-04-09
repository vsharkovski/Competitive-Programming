#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
struct User {
    int id;
    set<int> sent;
    set<int> received;
};
 
int findUserOrAdd(vector<User>& users, int id) {
    for (unsigned int i = 0; i < users.size(); ++i) {
        if (users[i].id == id) {
            return i; //return address of user
        }
    }
 
    //create new user and add them
    User u = {id};
    users.push_back(u);
 
    return users.size() - 1; //return address of new user
}
 
 
int main() {
    int n, k; //number of users, number of messages
    cin >> n >> k;
 
    vector<User> users;
 
    for (int i = 0; i < k; ++i) {
        int sId, rId; //senderId, receiverId
        cin >> sId >> rId;
 
        int sui = findUserOrAdd(users, sId); //get index of user with id=sId (or make new)
        users[sui].sent.insert(rId);
 
        int rui = findUserOrAdd(users, rId); //get index of user with id=rId (or make new)
        users[rui].received.insert(sId);
    }
 
    int BROJ = 0;
 
    for (unsigned int i = 0; i < users.size(); ++i) {
        User u = users[i];
        //cout << "user_id:" << u.id << endl;
 
        set<int>::iterator rit; //set iterator
        for (rit = u.received.begin(); rit != u.received.end(); ++rit) {
            int sid = *rit; //sender id
            //cout << "\tsender_id:" << sid << endl;
 
            if (u.sent.find(sid) == u.sent.end()) { //ako vo "received", vektor od lugje od koj primil u, NEMA id na nekoj na koj mu pratil
                BROJ++;
                //cout << "\tbroj e sega " << BROJ << endl;
            }
        }
    }
 
    cout << BROJ << endl;
}