#include"Plane.h"

enum Runway_activity{idle,lands,takeoffs};

class Runway{
public:
	Runway(int limit);
	bool can_land(const Plane &current);
	bool can_depart(const Plane &current);
	Runway_activity activity(int time,Plane &moving);
	void shut_down(int time)const;
private:
	queue<Plane> landing;
	queue<Plane> takeoff;
	int queue_limit;
	int num_land_requests;
	int num_takeoff_requests;
	int num_landings;
	int num_takeoffs;
	int num_land_accepted;
	int num_takeoff_accepted;
	int num_land_refused;
	int num_takeoff_refused;
	int land_wait;
	int takeoff_wait;
	int idle_time;
};