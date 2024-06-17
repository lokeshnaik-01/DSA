// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings;
        for(int i=0;i<n;i++)
            meetings.push_back({end[i],start[i]});
        sort(meetings.begin(),meetings.end());
        int totalMeetings = 1;
        
        //It is just to compare the end time of the last meeting that we did.
        
        //Always see first = endtime & second = starttime.
        
        int lastEnd = meetings[0].first;
        
        for(int i=1;i<n;i++)
        {
            //The condition asked in question that  Also note start time of one 
            //chosen meeting can't be equal to the end time of the other chosen meeting.
            if(meetings[i].second>lastEnd)
            {
                totalMeetings++;
                //We will only update our end time of our last meeting when we are doing.. 
                //This meeting
                lastEnd = meetings[i].first;
            }
        }
        
        return totalMeetings;
    }
};
