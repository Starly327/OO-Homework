#include<iostream>
#include<vector>
using namespace std;

class video{
public:
	string name;
	int basicPrice,latePrice;
	int basicDay,rentDay;
	int point;
	video(string name,int rentDay):name(name),rentDay(rentDay){}
    
    int getPrice(){
        int totalPrice=0;
        if(rentDay>basicDay){
            totalPrice = basicPrice + (rentDay - basicDay)*latePrice;
        }else{
            totalPrice = basicPrice;
        }
        return totalPrice;
    }
    
    
};

class newVideo:public video{
public:
	newVideo(string name,int rentDay):video(name,rentDay){
        basicPrice = 3;
        latePrice = 2;
        basicDay = 1;
        point = 2;
    }
};

class oldVideo:public video{
public:
	oldVideo(string name,int rentDay):video(name,rentDay){
        basicPrice = 2;
        latePrice = 1;
        basicDay = 3;
        point = 1;
    }
};

class childVideo:public video{
public:
	childVideo(string name,int rentDay):video(name,rentDay){
        basicPrice = 2;
        latePrice = 1;
        basicDay = 5;
        point = 0.5;
    }
};

class customer{
private:
    vector<video *> list;
public:
    void addVideo(video *v){
        list.push_back(v);
    }

    void getInfo(){
        cout<<"Movies: ";
        getVideo();
        cout<<endl<<"Total price: ";
        getPrice();
        cout<<"Total points: ";
        getPoint();
    }
    void getVideo(){
        for(unsigned idx=0; idx<list.size(); idx++)
            cout<<list[idx]->name<<"    ";
            
        
    }
    void getPrice(){
        int totalPrice=0;
        for(unsigned int i=0; i<list.size(); i++)
            totalPrice += list[i]->getPrice();
        cout<<totalPrice<<endl;
    }
    void getPoint(){
        int totalPoint=0;
        for(unsigned int i=0; i<list.size(); i++)
            totalPoint += list[i]->point;
        cout<<totalPoint<<endl;
    }
};

int main(){
    vector<customer> customerList;
    customer April,Joe;
    customerList.push_back(April);
    customerList.push_back(Joe);
    video *ptr;
    ptr = new oldVideo("WonderWoman",3);
    April.addVideo(ptr);
    ptr = new oldVideo("WonderWoman",2);
    Joe.addVideo(ptr);
    ptr = new newVideo("JusticeLeague",5);
    April.addVideo(ptr);
    ptr = new newVideo("Thor3",1);
    Joe.addVideo(ptr);

    cout<<"April:"<<endl;
    April.getInfo();
    cout<<"Joe:"<<endl;
    Joe.getInfo();
    return 0;
}