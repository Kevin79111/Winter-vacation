#include<iostream>

using namespace std;
class IMotor
{

public: 
	virtual void SetOutput(double a)=0;
	virtual double Getspeed()=0;
	virtual void Update()=0;

	virtual ~IMotor() {
		cout << "基类析构" << endl;
	 }
	
	
	
};

class DJIMotor: public IMotor
{   private:
	double input;
	public:
		virtual void SetOutput(double a) override {
			input = a;
			printf("[CAN BUS] ID:0x201,send current 500\n");
		}
		virtual double Getspeed() override{
			return 1000;
		}
		virtual void Update(){
		}
		 ~DJIMotor()override{
			cout << "DJ析构" << endl;
		}
};
class SimMotor :public IMotor {
    private:
	double input;
	double velocity_;
	double force;
    public:
		SimMotor(double b, double c):input(0),velocity_(b),force(c){}
        
		virtual void SetOutput(double a) override {
			input = a;
			
		}
		virtual double Getspeed() override {
			return velocity_;
		}

		virtual void Update() override {
			velocity_ = velocity_ + (input - force);
		}
		~SimMotor()override {
			cout << "Sim析构" << endl;
		}
		 
};

void testmotor(IMotor *p)
{
	p->SetOutput (100);
	p->Update();
	cout <<"速度为"<< p->Getspeed() << endl;
}
int main()
{   
	IMotor* pxy = new SimMotor(0,1);
	testmotor(pxy);
	delete pxy;

	IMotor* pxy2 = new DJIMotor();
	testmotor(pxy2);
	delete pxy2;


	system("pause");
	return 0;
}