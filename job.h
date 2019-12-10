#include<string>
using namespace std;

class Job {

private:
	int jobID;
	string userType;
	char jobType;
	int jobProcesser;
	double jobTime;
	double timeGeneration;
	double timeStart;
	double timeFinish;
	double timeCurrent;
	bool useGPU;
	double waitingTime;
	
public:
	void setjobID(int jobid);
	int getjobID();

	void setjobProcesser(int jobprocesser);
	int getjobProcesser();


	void setuserType(string usertype);
	string getuserType();

	void setjobType(char type);
	char getjobType();

	void settimeGeneration(double timegeneration);
	double gettimeGeneration();

	void settimeStart(double timestart);
	double gettimeStart();

	void settimeFinish(double timefinish);
	double gettimeFinish();

	void settimeCurrent(double timecurrent);
	double gettimeCurrent();

	void setjobTime(double jobtime);
	double getjobTime();

	void setwaitingTime(double waitingtime);
	double getwaitingTime();

	void setuseGPU(bool usegpu);
	bool getuseGPU();
};