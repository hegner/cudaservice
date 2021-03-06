#include <iostream>
#include <fstream>
#include <future>
#include <chrono>
#include <algorithm>
#include "../src/implementations/taskService_stat.cpp"
#include "cudaservice/task_service/thread_pool.h"
using namespace std;
using namespace edm::service;

template<class Fn, class... Args>
decltype(auto) launch1(Fn&& f, Args&&... args){
	return thread(forward<Fn>(f), forward<Args>(args)...);
}
void f(int a){
	cout<<"Hello from _f_! a= "<<a<<"\n";
}

int main(int argc, char** argv)
{
	TaskServiceStat statServ;
	/*int n=7;
	statServ.set_task<void(int*)>(0, f);
	statServ.launch<void(int*)>(0, n).get();
	return 0;*/

	long N= 10000;
	if (argc>1) N= stol(argv[1]);
	auto start= chrono::steady_clock::now();
	auto end = start;
	auto diff= start-start;
	future<void> fut;

	long dummy= 1;

	ofstream f("dump");
	ThreadPoolService pool(std::thread::hardware_concurrency());
	/*diff= start-start;
	for (int i = 0; i <= N; ++i)
	{
		//dummy= 0;
		start = chrono::steady_clock::now();
	  fut= pool.enqueue([&f] (long dummyArg){
			dummyArg= 2;
			f << 1;
	  }, dummy);
		end = chrono::steady_clock::now();
		fut.get();
		diff += (i>0)? end-start: start-start;
	}
	cout << "ThreadPoolService: "<< chrono::duration <double, nano> (diff).count()/N << " ns" << endl;*/

	vector<future<void>> futVec;
	diff= start-start;
	for (int i = 0; i <= N; ++i)
	{
		start = chrono::steady_clock::now();
	  futVec.push_back(pool.enqueue([&f] (){
	  }));
		end = chrono::steady_clock::now();
		diff += (i>0)? end-start: start-start;
	}
	cout << "Vec ThreadPoolService: "<< chrono::duration <double, nano> (diff).count()/N << " ns" << endl;
	for_each(futVec.begin(), futVec.end(), [] (auto&& elt) {
		elt.get();
	});

/*
	diff= start-start;
	for (int i = 0; i <= N; ++i)
	{
		//dummy= 0;
		start = chrono::steady_clock::now();
		statServ.set_task<void(long)>(i, [&f] (long dummyArg){
			dummyArg= 2;
			f << 1;
		});
		fut= statServ.launch<void(long)>(i, dummy);
		end = chrono::steady_clock::now();
		fut.get();
		diff += (i>0)? end-start: start-start;
	}
	//cout << dummy << endl;
	cout << "Static: "<< chrono::duration <double, nano> (diff).count()/N << " ns" << endl;
*/
	f.close();
	return 0;
}
