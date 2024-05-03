#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Observer Interface
class Observer
{
    public:
         virtual void update (const string & weather) = 0;
};

// Subject Interface
class Subject
{
    public:
        virtual void addObserver (Observer * observer) = 0;
        virtual void removeObserver (Observer * observer) = 0;
        virtual void notifyObservers () = 0;
};

// ConcreteSubject Class
class WeatherStation:public Subject
{
    private:
        vector < Observer * >observers;
        string weather;

    public:
        void addObserver (Observer * observer) override
        {
	        observers.push_back (observer);
        }

        void removeObserver (Observer * observer) override
        {
	        // Find and remove the observer
	        for (auto it = observers.begin (); it != observers.end (); ++it)
	        {
		        if (*it == observer)
		        {
			        observers.erase (it);
			        break;
		        }
	        }
        }

        void notifyObservers () override
        {
            for (Observer * observer:observers)
	        {
		        observer->update (weather);
	        }
        }

        void setWeather (const string & newWeather)
        {
	        weather = newWeather;
	        notifyObservers ();
        }
};

// ConcreteObserver Class
class PhoneDisplay:public Observer
{
    private:
        string weather;

    public:
        void update (const string & weather) override
        {
	        this->weather = weather;
	        display ();
        }

        void display ()
        {
	        cout << "Phone Display: Weather updated - " << weather << endl;
        }
};

// ConcreteObserver Class
class TVDisplay:public Observer
{
    private:
        string weather;

    public:
        void update (const string & weather) override
        {
	        this->weather = weather;
	        display ();
        }

        void display ()
        {
	        cout << "TV Display: Weather updated - " << weather << endl;
        }
};

// Usage Class
int main ()
{
  WeatherStation weatherStation;

  Observer *phoneDisplay = new PhoneDisplay ();
  Observer *tvDisplay = new TVDisplay ();

  weatherStation.addObserver (phoneDisplay);
  weatherStation.addObserver (tvDisplay);

  // Simulating weather change
  weatherStation.setWeather ("Sunny");

  // Output:
  // Phone Display: Weather updated - Sunny
  // TV Display: Weather updated - Sunny

  // Clean up memory (optional)
  delete phoneDisplay;
  delete tvDisplay;

  return 0;
}