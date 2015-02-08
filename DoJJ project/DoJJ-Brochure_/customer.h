#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

// E N U M S
enum Interest{
    VERY,
    SOMEWHAT,
    NOT,
    NEVER_CALL
};


// C L A S S E S
//stringType - Allows use of either QString or std::string
template <class stringType>
class Customer{
    public:
        // CONSTRUCTORS
        Customer();
        Customer(stringType newName, stringType newAddress,
                 bool newKeyCust, bool newHasBrochure,
                 Interest newInterest, stringType newTestimonial);
        ~Customer();

        // MUTATORS
        void SetCompName(stringType newName);
        void SetAddress(stringType newAddress);
        void SetKey(bool newKeyCust);
        void SetBrochureStat(bool newHasBrochure);
        void SetInterest(Interest newInterest);
        void SetTestimonial(stringType newTestimonial);

        // ACCESSORS
        stringType GetCompName() const;
        stringType GetAddress() const;
        stringType GetKey() const;
        stringType GetBrochureStat() const;
        bool       GetBrochure() const;
        stringType GetInterest() const;
        stringType GetTestimonial() const;

    private:
        stringType compName;
        stringType address;
        bool isKey;
        bool hasBrochure;
        stringType testimonial;
        Interest custInterest;
};

template <class stringType>
Customer<stringType>::Customer(){
    SetCompName("");
    SetAddress("");
    SetKey(false);
    SetBrochureStat(false);
    SetInterest(NOT);
    SetTestimonial("");
}

template <class stringType>
Customer<stringType>::Customer(stringType newName, stringType newAddress,
                               bool newKeyCust, bool newHasBrochure,
                               Interest newInterest, stringType newTestimonial){
    SetCompName(newName);
    SetAddress(newAddress);
    SetKey(newKeyCust);
    SetBrochureStat(newHasBrochure);
    SetInterest(newInterest);
    SetTestimonial(newTestimonial);
}

template <class stringType>
Customer<stringType>::~Customer(){
}

// M U T A T O R S
template <class stringType>
void Customer<stringType>::SetCompName(stringType newName){
    compName = newName;
}

template <class stringType>
void Customer<stringType>::SetAddress(stringType newAddress){
    address = newAddress;
}

template <class stringType>
void Customer<stringType>::SetKey(bool newKeyCust){
    isKey = newKeyCust;
}

template <class stringType>
void Customer<stringType>::SetBrochureStat(bool newHasBrochure){
    hasBrochure = newHasBrochure;
}

template <class stringType>
void Customer<stringType>::SetInterest(Interest newInterest){
    custInterest = newInterest;
}

template <class stringType>
void Customer<stringType>::SetTestimonial(stringType newTestimonial){
    testimonial = newTestimonial;
}

// A C C E S S O R S
template <class stringType>
stringType Customer<stringType>::GetCompName() const{
    return compName;
}

template <class stringType>
stringType Customer<stringType>::GetAddress() const{
    return address;
}

template <class stringType>
stringType Customer<stringType>::GetKey() const{
    stringType keyStat = "";

    if(isKey == true){
        keyStat = "Key";
    }
    else
    {
        keyStat = "Nice to Have";
    }
    return keyStat;
}

template <class stringType>
stringType Customer<stringType>::GetBrochureStat() const{
    stringType brochureStat = "False";

    if(hasBrochure == true){
        brochureStat = "True";
    }

    return brochureStat;
}

template <class stringType>
bool Customer<stringType>::GetBrochure() const{
    bool brochureStat = false;

    if(hasBrochure == true){
        brochureStat = true;
    }

    return brochureStat;
}

template <class stringType>
stringType Customer<stringType>::GetInterest() const{
    stringType interestLvl;

    switch(custInterest){
        case VERY        : interestLvl = "Very Interested";
                           break;
        case SOMEWHAT    : interestLvl = "Somewhat Interested";
                           break;
        case NOT         : interestLvl = "Not Interested";
                           break;
        case NEVER_CALL  : interestLvl = "Never Call Again";
                           break;
        default          : interestLvl = "Not Specified";
                           break;
    }

    return interestLvl;
}

template <class stringType>
stringType Customer<stringType>::GetTestimonial() const{
    return testimonial;
}

#endif // CUSTOMER_H
