# ENGG1340-COMP2113-Course-Project

## Table of Content
- [Team Infromation](#Team)
- [The Game / Theme](#Theme)
- [Installations](#Installations)
- [Instructions](#Instructions)
- [Features / Code Requirement](#Features)
- [Game Mechanics](#Mechanics)


## Team
Team Number: 96

Members: Mike CHENG Mo Shun (3035688825), Ivan NG Chak Ming (3035564976)

Topic: Global Pandemic Management as the World Health Organization

## Theme
This is a single-player card/strategy game, with global pandemic containment and control as the theme. The player plays as the World Health Organization chairperson. The player needs to prioritize his/her objectives, utilize the limited resources, and try his/her best to cooperate with different nations to defeat the virus.

## Installations
To install the game, simply navigate to the clone the repo and run the setup file, the game executable is named startgame.

```
git clone "https://github.com/ivan0313/Global-Pandemic-Management-as-the-World-Health-Organization.git"
cd Global-Pandemic-Management-as-the-World-Health-Organization
./setup.sh
./startgame
```

## Instructions
This section outlines the basic game rules.

The goal of the game is to reach a performance index of 80, at the same time avoid the performance index from falling below 30.

At the start of the game, you can choose to start a new game, or load an old save from the previous game, if this is not the first time you are playing.
The game is divided into days, you will enter a game menu after starting the game, where information like resources, simplified statistics of all countries, number of days passed, days left until the next income day, etc. will be displayed.

You then can choose to 1. view detail statistics of all countries, 2. view the market or 3. view action cards, by entering 1, 2, or 3. After using an action card, you will be brought to the random event stage. Finally, the day is over and you are returned to the game menu to start day 2.

### View Detail Statistics of all countries
After entering 1, you will be shown all the statistics of the first country, to view another country, simply enter the corresponding number. Enter 0 to exit the detailed statistics page back to the game menu.

### Market
After entering 2, you will be brought to the market, where you can purchase more staff to work for you or buy more medical equipment. These resources along with your money are required to use action cards in the later stages. You can also buy an action card from the market if you do not want to use the 3 action card you have for this round, these action cards will only cost you the capital required to buy the card with no other costs.

### Action Cards
After entering 3, you will be shown the 3 choices action cards, you may choose to use any one of the cards given you have enough resources. Performing this action will end the day. You may exit by entering 1, or select an action card to move on to the next stage.

### Random Event Cards
After using an action card, a random event card will be used, where the effects will be shown on screen. Pressing Enter will bring you back to the game menu and day 2 will start.

## Features
This section outlines the list of features and functions that we have implemented, it is a vis-a-vis of each of the items 1 to 5 listed under coding requirements in the project guide.

### Generation of random game sets or events
Random numbers are generated using time as the seed, it is used in function random_insert_to_trash() (found in linkedlist.cpp) to move the 3 action cards of each day randomly into the linked list trash, this allows for the reshuffle of cards after the player used up all cards in the deck.

Random distribution is used for calculating the increase in the number of infections, deaths, and recoveries each day. A Poisson distribution from <random> with a Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits as the random generator. The distributions take the current number multiplied by a factor or probability as the mean.

### Data structures for storing game status
The game status is divided into 3 main parts, countries, cards, and WHO. Since all parts contain various variables with different data types, we have built a different struct for each part to consolidate all variables and data. Since there are multiple cards and countries, a dynamic array of the structs is used. This allows for the manipulation of multiple struct country and card variables at the same time.

### Dynamic memory management
Dynamic array is used to store action cards, random event cards, and countries. This allowed us to change the size of the array when it is full.

We have also built multiple linked lists, used in storing the list of the card deck and trash for used cards. Not only can this facilitate the random insertion of cards as previously mentioned, we are also able to free all dynamic memory, such as the linked list and the dynamic array before the game is closed.


### File input/output (e.g., for loading/saving game status)
For easy editing of game settings, initial values for countries' statistics, action cards, and random event cards, these are all saved in a text file. To prevent the player from editing the text file directly, the file is encrypted using the caesar shift encryption method, using the line before as the encryption key. The encrypted file is then read into the program, decrypted, and loaded to initial a new game. Similarly, when the player saves a game, the game data are encrypted and stored in another text file, so the user may continue the game progress next time they start up the game.

When storing the initialization game status or game progress, information is separated by newlines and also special character ',' for easier visualization for us if we want to make changes to the file.

### Program codes in multiple files
Since the game program contains a huge number of lines of codes, putting everything in a single file is impossible for debugging and collaboration. Therefore, we have decided to separate different game functions into different files,

### Others
The game UI makes use of various Linux shell commands. The system() function is used to send the commands, such as `clear` in clearscreen(), `rm` to remove game progress txt file when the game is won or lost, and `touch` to create txt files for a new game.

## Mechanics
### Goal
The player wins the game by obtaining a performance index (PI) above the winning threshold, similarly, the player loses if the PI goes below the losing threshold. The player must perform at most one action each day to respond to different random generated scenarios and try to contain the virus.

### Performance index (PI)
The PI is the average of the individual countries’ Index (ICI), calculated using the formula below:

[ PI = (Sum of individual countries' index * countries population) / Total Population ]

Each country has an individual country index (ICI), this is affected by a few main factors, namely the infection rate, number of deaths, number of recoveries, and economic impact caused by the virus.

### Capital & Medical equipment.
The game will have a simple resource system, where the three resources are capital(money) staff and medical equipment. The player will start with an initial capital of 5000, and will continuously receive a steady income stream every week. Another source of income will be from random events, while some random events will lead to the deduction of capital. Medical equipment and staff can be obtained from the market by using capital. Random events will also affect the accumulation and consumption of quantities of medical equipment. The player will need to use varying amounts of capital and medical equipment to use action cards.

### Cards
Cards are a major component of the game. There are two types of cards, action cards, and random event cards. Action cards will be drawn randomly to the player each day where the player can choose one to use. Each action card will have different money, staff, and equipment cost, they will also have different benefits, such as slowing down infection rate or reducing economic activities. Players will have the option to get 3 new action cards before the day ends by sacrificing money. Random event cards, on the other hand, will be drawn once every day, players will not have control over which card to use, each random event card will also have its effect.

### Game Flow
The game is divided into different days. Each day, the player will draw 3 new action cards from the deck. The player will select 1 card to use, and then the cards will be discarded to the bin. Once an action card is selected, a random event card will be drawn, and the day will end. The effect of the action card or any random event card will be reflected in the next day. Players can enter the market to purchase more medical equipment or hire new staff anytime during the day. If there are no more cards in the deck, cards from the bin will be shuffled and returned to the deck.
