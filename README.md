# ENGG1340-COMP2113-Course-Project

## Team Information
Team Number: 96

Members: Mike CHENG Mo Shun (3035688825), Ivan NG Chak Ming (3035564976)

Topic: Global Pandemic Management as the World Health Organization

## The Game
This section describe the game briefly.

## Instructions
This section outline the basic game rules.

The goal of the game is to reach a performance idex of 80, at the same time avoid the performance index from falling below 30.

In the start of the game, you can choose to start a new game, or load an old save from the previous game, if this is not the first time you are playing.
The game is divided into days, you will enter a game menu after starting the game, where information like resources, a simplifed statistics of all countries, number of day passed, days left until the next income day, etc. will be displayed.

You then can choose to 1. view detail statistics of all countries, 2. view the market or 3. view action cards, by entering 1, 2, or 3. After using an action card, you will be brought to the random event stage. Finally the day is over and you are returned to the game menu to start day 2.

### View Detail Statistics of all countries
After entering 1, the you will be shown all the statistics of the first country, to view another country, simpily enter the corresponding number. Enter 0 to exit the detail statistics page back to the game menu.

### Market
After entering 2, you will be brought to the market, where you can purchase more staff to work for you or buy more medical equipments. These resources along with your money are required to use action cards in the later stages. You can also buy an action card from the market if you do not want to use the 3 action card you have for this round, these action cards will only cost you the capital required to buy the card with no any other costs.

### Action Cards
After entering 3, you will be shown the 3 choices action cards, you may choose to use any one of the cards given you have enough resources. Performing this action will end the day. You may exit by entering 1, or select an action card to move on to the next stage.

### Random Event Cards
After using an action card, a random event card will be used, where the effects will be shown on screen. Pressing Enter will bring you back to the game menu and day 2 will start.

## Features
This section outlines the list of features and functions that we have implemented, it is a vis-a-vis of each of the items 1 to 5 listed under coding requirements in the project guide.

### Generation of random game sets or events
Random numbers are generate using time as the seed, it is used in function random_insert_to_trash() (found in linkedlist.cpp) to move the 3 action cards of each day randomly into a linked list trash, this allows for the reshuffle of cards after the player used up all cards in the deck.

Random distribution is used for calculating the increase in number of infections, deaths and recoveries each day. A poission distribution from <random> with a Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits as random generator. The distributions takes the current number mulitplied by a factor or probability as the mean.

### Data structures for storing game status
The game status is divided into 3 main parts, countries, cards and WHO. Since all parts contains various variables with different data types, we have built a different struct for each part to consolidate all variables and data.
	(e.g. country, card and who)

### Dynamic memory management
Using dynamic_array so that the size of array will change when the array is full.
	(e.g. actions cards array and random action cards array)

Building list and dynamic memory
	(e.g. deck list and trash list)

Free all dynamic memory
	(free entire lists and dynamic arrays)

### File input/output (e.g., for loading/saving game status)
Encryption and Decyrption in store and read file
	(prevent player change their game status from txt files)

Use find function to find the position of specific character(i.e. ',')

### Program codes in multiple files

### Others
Use system() to perform linux command to shell
	(e.g. clear [clear screen], rm [remove txt files], touch [create txt files])

## Theme
This is a single player card/strategy game, with global pandemic containment and control as theme. The player plays as the World Health Organization chairperson. The player needs to prioritize his/her objectives and try his/her best to cooperate with different nations to defeat the virus.

## Game Mechanics
### Goal
The player wins the game by obtaining a performance index (PI) above the winning threshold, similarly, the player loses if the PI goes below the losing threshold. The player must perform at most one action each day to respond to different random generated scenarios and try to contain the virus.

### Performance index (PI)
The PI is the average of the individual countries’s Index (ICI), calculated using the formula below:

[ PI = (Sum of individual countries' index * countries population) / Total Population ]

Each country has an individual country index (ICI), this is affected by two main categories of factors, namly the death rate and economic impact caused by the virus. Two main categories each contribute half to the country’s ICI. The respective factors are listed below:

Category          Factor                    Relation to Category
Death Rate        Flow of people                  +ve
                  Public awareness                -ve
                  Infection Rate                  +ve
                  Available medical Supply        -ve
Economic Impact   Flow of people                  -ve
                  Public awareness                +ve
                  Infection Rate                  +ve

### Capital & Medical equipment.
The game will have a simple resource system, where the two resources are capital(money) and medical equipment. The player will start with an initial capital of 100k, and will continuously receive a varying income stream every month. The income stream will vary with the performance index. Another source of income will be from random events, while some random events will lead to deduction of capital.

Medical equipment is obtained by using capital to produce from the factory. Price of producing medical equipment will fluctuate with the performance index, whereas the production time will always be instant. Random events will also affect the accumulation and consumption of quantities of medical equipment.

The player will need to use varying amounts of capitals and medical equipment to use action cards. Detail costs and effects of each action card are listed in the next section.

### Cards
Cards are a major component of the game. There are two types of cards, action cards and random event cards. Action cards will be drawn randomly to the player each day where the player can choose one to use. Each action card will have different money, staff and equipment cost, they will also have different benefits and drawbacks, such as slowing down infection rate, or inducing more panic. Players will have  the option to get 3 new action cards before the day ends by sacrificing money. Random event cards on the other hand will be drawn once everyday, players will not have control over which card to use, each random event card will also have its own effect.

### game flow
The game is divided into different days. Each day, the player will draw 3 new action cards from the deck. The player will select 1 card to use, and then the cards will be discarded to the bin. Once an action card is selected, a random event card will be drawn, and the day will end. The effect of the action card or any random event card will be reflected in the next day. Players can enter the production centre to produce more medical equipment or hire new staff anytime during the day. If there are no more card in the deck, cards from the bin will be shuffled and returned to the deck.


## Code Requirement
### Generation of random game sets or events
Factors affecting the ICI are modelled using various probability models, actions performed by users do not directly impact the factors affecting ICI, they only affect the parameter of the random distribution. Infection rate, recovery rate and death rates will be modelled using poisson, exponential or geometric random variables. Players will receive action cards randomly according to how common the card is. The same goes for random events.

Reference:
Header <Random> http://www.cplusplus.com/reference/random/
Exponential distribution http://www.cplusplus.com/reference/random/exponential_distribution/

### Data structures for storing game status
An array of struct variables will be used to store infection statistics of different countries. Game status like number of days passed, amount of capital, medical equipment and number of staff are stored in another array.

### Dynamic memory management
Dynamic memory will be used to store the cards in the deck or in the trash bin, lists will be used for the deck so constant time insertion and erasing can be performed anywhere within the sequence. Another dynamic memory will also be used to keep track of the game's status history, so the player’s performance can be shown after the game is over. Dynamic memory is used as the number of days of each game is unknown.


### File input/output (e.g., for loading/saving game status)
Since players can start a new game or load an old game anytime, the game status will be stored using file inputs and outputs. To prevent players from changing the game status directly using a text editor, caesar shifting encryption will be used to protect the save data.

### Program codes in multiple files
Other than the main file, the program will be separated into different files that only contain limited related functions. For example, functions for game menu, game initialization, load old saves, loops of each round in game, user performing an action, printing game screen, saving games and settings will all be written in a different file.
