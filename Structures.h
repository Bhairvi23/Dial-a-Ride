typedef struct
{
    int start_time;
    int end_time;
    int start_loc;
    int end_loc;
    int status=0; 
}request;
typedef struct 
{
  int initial_loc;
  vector<int> route;
  int capacity;
  int revenue;
}vehicle;
