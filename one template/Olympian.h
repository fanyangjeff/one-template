//
//  Olympian.h
//  one template
//
//  Created by YF on 18/03/2018.
//  Copyright © 2018 YF. All rights reserved.
//

#ifndef Olympian_h
#define Olympian_h
#include <iomanip>


class Olympian
{
public:
    Olympian() = default;
    Olympian(std::string n, std::string sp, std::string st, char g, int a, int h, int ng, int ns, int nb)
    {
        name = n;
        sport = sp;
        state = st;
        gender = g;
        age = a;
        height = h;
        nGold = ng;
        nSilver = ns;
        nBronze = nb;
    }
    
    void setkey(std::string key){this->name = key;}
    void setName(std::string n) { name = n; }
    void setSport(std::string s) { sport = s; }
    void setState(std::string s) { state = s; }
    void setGender(char g) { gender = g; }
    void setHeight(int h) { height = h; }
    void setAge(int a) { age = a; }
    void setnGold(int g) { nGold = g; }
    void setnSilver(int s) { nSilver = s; }
    void setnBronze(int b) { nBronze = b; }
    
    std::string getName() const { return name; }
    std::string get_key() const {return this->name;}
    std::string getSport() const { return sport; }
    std::string getState() const { return state; }
    char setGender() const { return gender; }
    int getAge() const { return age; }
    int getHeight() const { return height; }
    int getnGold() const { return nGold; }
    int getnSilver() const { return nSilver; }
    int getnBronze() const { return nBronze; }
    
    friend std::ostream &operator<<(std::ostream&, const Olympian&);
    
private:
    std::string name;
    std::string state;
    std::string sport;
    char gender;
    int height;
    int age;
    int nGold;
    int nSilver;
    int nBronze;
};



std::ostream& operator<<(std::ostream& os, const Olympian& olympian)
{
    os<<left<<setw(7)<<olympian.name
    <<setw(10)<<olympian.sport
    <<setw(12)<<olympian.state
    <<setw(4)<<olympian.gender
    <<setw(4)<<olympian.age
    <<setw(4)<<olympian.height
    <<setw(4)<<olympian.nGold
    <<setw(4)<<olympian.nSilver
    <<setw(4)<<olympian.nBronze<<endl;
    
    return os;
}



#endif /* Olympian_h */
