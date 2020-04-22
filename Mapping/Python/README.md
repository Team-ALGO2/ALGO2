# Python Tools

> NOTE: Instructions For **Linux** Only
> NOTE: Instructions For Python 3.6.8. Experiences With Other Versions May Vary!


## Installation

### Make Sure To Have Python Installed
`sudo apt-get update`  
`sudo apt-get install python3`

### Install pip
`sudo apt-get install python3-pip`

### Install virtualenv Using pip
(If you want to install globally)  
`sudo pip3 install virtualenv`  
(If you want to install locally)  
`pip3 install --user virtualenv`

### Go To Home Directory
It should be the main folder where the project is located

### Create Virtual Environment
`virtualenv python-venv`  
--alternatively--
`python3 -m venv python-venv`  
**!!Please keep the name python-venv!!**  
> If you want to use a different name, make sure it is **gitignored!!!**  
Please **Do Not** upload 3 gigs of python data onto the github

### Launch Virtual Environment
`source python-venv/bin/activate`

### Install Requirements
`pip3 install -r requirements.txt`

### Done!
Congratulations, your environment is successfully set up!

### Exiting Virtual Environment
Just type `deactivate` in the command line
