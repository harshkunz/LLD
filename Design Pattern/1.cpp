#include <bits/stdc++.h>
using namespace std;

// strategy interface for walk
class WalkableRobot {
    public:
        virtual void walk() = 0;
        virtual ~WalkableRobot() {}
};

// concrete strategies for walk
class NormalWalk: public WalkableRobot {
    public:
        void walk() override {
            cout<<"walking normal"<<endl;
        }
};

class NoWalk: public WalkableRobot {
    public:
        void walk() override {
            cout<<"no walk"<<endl;
        }
};


// strategy interface for talk
class TalkableRobot {
    public:
        virtual void talk() = 0;
        virtual ~TalkableRobot() {}
};

// concrete strategies for talk
class NormalTalk: public TalkableRobot {
    public:
        void talk() override {
            cout<<"talking normal"<<endl;
        }
};

class NoTalk: public TalkableRobot {
    public:
        void talk() override {
            cout<<"no talk"<<endl;
        }
};


// strategy interface for fly
class FlyableRobot {
    public:
        virtual void fly() = 0;
        virtual ~FlyableRobot() {}
};


// concrete strategies for fly
class NormalFly: public FlyableRobot {
    public:
        void fly() override {
            cout<<"flying normal"<<endl;
        }
};

class NoFly: public FlyableRobot {
    public:
        void fly() override {
            cout<<"no fly"<<endl;
        }
};


// robot base class
class Robot {
    protected:
        WalkableRobot* walkBehavior;
        TalkableRobot* talkBehavior;
        FlyableRobot* flyBehavior;

    public:
        Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f){
            this->walkBehavior = w;
            this->talkBehavior = t;
            this->flyBehavior = f;
        }

        void walk() {
            walkBehavior->walk();
        }

        void talk() {
            talkBehavior->talk();
        }

        void fly() {
            flyBehavior->fly();
        }

        virtual void projection() = 0;
};

// concrete robot types
class CompanionRobot: public Robot {
    public:
        CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

        void projection() override {
            cout<<"robot with companion features"<<endl;
        }
};

class WorkerRobot: public Robot {
    public:
        WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

        void projection() override {
            cout<<"robot with working features"<<endl;
        }
};


// main function
int main() {
    Robot *r1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    r1->walk();
    r1->talk();
    r1->fly();
    r1->projection();

    cout<<"break"<<endl;

    Robot *r2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    r2->walk();
    r2->talk();
    r2->fly();
    r2->projection();
}






