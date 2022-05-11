#include<bits/stdc++.h>
using namespace std;

class video{
public:
	string name;
	int basicPrice,latePrice;
	int basicDay;
	int point;
	video(string name){
        this->name = name;
    }
    
    
    
};

class newVideo:public video{
public:
	newVideo(string name):video(name){
        basicPrice = 3;
        latePrice = 2;
        basicDay = 1;
        point = 2;
    }
};

class oldVideo:public video{
public:
	oldVideo(string name):video(name){
        basicPrice = 2;
        latePrice = 1;
        basicDay = 3;
        point = 1;
    }
};

class childVideo:public video{
public:
	childVideo(string name):video(name){
        basicPrice = 2;
        latePrice = 1;
        basicDay = 5;
        point = 0.5;
    }
};

class customer{
public:
    string name;
    int totalCost;
    int totalPoint;
    customer(string name){
        this->name = name;
        totalCost = 0;
        totalPoint = 0;
    }
};

class rentRecord{
public:
    customer *c;
    video *v;
    int day;
    rentRecord(customer *c, video *v, int day){
        this->c = c;
        this->v = v;
        this->day = day;
    }
};

class manage{
public:
    set<customer*> customerList;
    set<video*> videoList;
    vector<rentRecord *> rentList;

    void addCustomer(customer *c){
        customerList.insert(c);
    }
        
    void addVideo(video *v){
        videoList.insert(v);
    }

    void addRecord(customer *c, video *v, int totalDay){
        rentRecord *r = new rentRecord(c,v,totalDay);
        rentList.push_back(r);
        c->totalCost += (totalDay > v->basicDay)?v->basicPrice + (totalDay - v->basicDay) * v->latePrice:v->basicPrice;
        c->totalPoint += v->point;
    }

    void printRecord(customer *c){
        cout<<c->name<<endl;
        cout<<"Movies: ";
        for(auto rent:rentList){
            if(rent->c==c)
                cout<<rent->v->name<<"  ";
        }
        cout<<endl<<"Total cost: ";
        cout<<c->totalCost<<endl;
        cout<<"Total points: ";
        cout<<c->totalPoint<<endl;
    }
};

int main(){
    manage m;
    customer *april = new customer("April");
    customer *joe = new customer("Joe"); 
    video *wonderWoman = new oldVideo("WonderWoman");
    video *justiceLeague = new newVideo("JusticeLeague");
    video *thor3 = new newVideo("Thor3");

    m.addCustomer(april);
    m.addCustomer(joe);
    m.addVideo(wonderWoman);
    m.addVideo(justiceLeague);
    m.addVideo(thor3);

    m.addRecord(april,wonderWoman,3);
    m.addRecord(joe,wonderWoman,2);
    m.addRecord(april,justiceLeague,5);
    m.addRecord(joe,thor3,1);
    
    m.printRecord(april);
    m.printRecord(joe);
}