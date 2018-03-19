//
//  main.cpp
//  two templates
//
//  Created by YF on 06/03/2018.
//  Copyright © 2018 YF. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include "Hash.h"
#include "Olympian.h"



long hash_string(Olympian *hash_object, const int size)
{
    int sum = 0;
    for(int i=0; i < hash_object->get_key().size(); i++)
        sum += hash_object->get_key()[i] * hash_object->get_key()[i] * hash_object->get_key()[i];
    
    return sum % size;
    
}



int compareName(Olympian* left, Olympian *right)
{
    if(left->get_key() == right->get_key())
        return 1;
    
    return 0;
}


int main(int argc, const char * argv[]) {

    const int SIZE = 100;
    const int size_bucket = 3;
    
    std::string name[7] = {"Jeff", "effJ", "Jffe", "ffJe", "eJff", "Aidan", "AJ"};
    std::string states[7] = {"Utah", "Ohio", "Alabama", "Soviet Union", "Washington", "New York", "Colorado"};
    std::string sports[7] = {"soccer", "basketball", "volleyball", "guitar", "baseball", "golf", "tennis"};
    char gender[7] = {'m','f','f','f','m','m','m'};
    


    int age[7] = {24, 23, 22, 21, 23, 24, 23};
    int height[7] = {6, 5, 6, 6, 5, 4, 3};
     int ng[7] = {3, 9, 2, 3, 1, 2, 3};
     int ns[7] = {4, 3, 2, 1, 3, 2, 5};
     int nb[7] = {2, 3, 2, 6, 5, 4, 2};
    
    
    Hash<Olympian*> hash(compareName, hash_string, SIZE, size_bucket);
    
    
    Stack<Olympian*> s_object;
    
    Olympian *olympian[7];
    
    for(int i=0; i<7; i++)
        olympian[i] = new Olympian(name[i], sports[i],states[i],  gender[i], age[i], height[i], ng[i], ns[i], nb[i]);
    

    
    for(int i=0; i<7; i++)
    {
       hash.insert(olympian[i]);
    }
    
    hash.printStats();
    
    char next = 'Y';
    string key;
    bool success;
    Olympian *outData;

   
    while(next == 'Y')
    {
        outData = new Olympian;
        
        cout<<"please enter the name you wanna delete\n";
        cin>>key;
        outData->setkey(key);
        success = hash.remove(outData);
        
      //  delete_data_storage(s_object, outData);
        
        if(success)
        {
          //  cout<<*outData;
            cout<<"the removal was successful\n";
        }
        cout<<"continue press Y\n";
        cin>>next;
    }
    
    
     next = 'Y';
    while(next == 'Y')
    {
        outData = new Olympian;
        cout<<"please enter the name you wanna search\n";
        cin>>key;
        
        outData->setkey(key);
        
        success = hash.findEntry(outData);
        
        if(success)
            cout<<*outData;
        
        cout<<"continue press Y\n";
        cin>>next;
    }

    
  /*
    cout<<"do you wanna put all the data back?\n";
    char choice;
    cin>>choice;
    
    if(choice == 'Y')
    {
        int index = 0;
        StuInfo *In[s_object.getCount()];
        
        for(int i=0; i<s_object.getCount(); i++)
            In[i] = new StuInfo;
        
        while(undo_deletion(s_object, In[index] ))
        {
            cout<<*In[index]<<endl;
            hash.insert(In[index]);
            index ++;
        }
    }
    next = 'Y';
    while(next == 'Y')
    {
        outData = new StuInfo;
        cout<<"please enter the name you wanna search\n";
        cin>>key;
        outData->set_key(key);

        
        success = hash.findEntry(outData);
        
        if(success)
            cout<<*outData;
        
        cout<<"continue press Y\n";
        cin>>next;
    }
    */


    return 0;
}
