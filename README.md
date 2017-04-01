# HoneyBee Simulator
## Objective
This program will simulate the lifecycle of a single bee hive to simulate colony reproduction and potential for random genetics to result in hive unsustainability. 

## Methodology
The program will simulate a single hive and basic genetic dispersion from the Queen to the workers and drones. Simple traits of honey and pollen production, aggressiveness, population tolerance are used to for this simulation to run a simulation to monitor the production and consumption of food resources in balance with Queen brood production rates and queens population disbursement of brood.  This iteration of the simulation will account for only one hive and the drones mating with new Queens will be randomly created to represent Drones from other hives. Queens mate with up to 16 Drones during the mating period and then randomly mixed the genetic distribution over her eggs throughout her life. The simulation will not assume that all queens are so successful, as does nature. 
  Worker bee job progressions throughout lifecycle has bee simplified for this simulation such that guards, fanners, waxing, and packers have been reduced to simply hive under the enum for worker bee jobs.
  Honey bee consumption is approximated from personal bee keeping experience of hive food stores, populations, and 4 month winter periods on average. This is not a perfect model to based from as warm periods will have all the hive bees moving more and consuming more food, but when factored and balanced with the harvester bees simply eating in the field and bringing home the excess it should be a statistical approximate to assert they balance and serve a stable model to simulate.  Here are the quick numbers for bee consumption based on hands on results over the years:
~days = 122 
~Colony size = 45,000 bees
~Frames of honey consumed for the period = 14 deep frames 
~6 lbs honey per deep frame
~8,ooo cells per deep frame

(14 frames X 8,000 cells) / 122 days = 918 cells consumed a day by the colony
918 cells / 45,000 bees =  0.0204 cells consumed per day per bee

96ozs (6lbs) honey / 8,000 Cells = 0.012 ozs Honey per cell

Thus a single bee ~consumes
 0.0204 cells per day * 0.012 oz per cell = 0.0002448 oz honey per day

The same size hive will average producing 20 to 30 deep frames of honey over the harvest season (I'll use the mean of 25 **this is a small hive, but we split a lot so we have a good background of small hive production**).
25 frames * 96oz = 2400 oz honey in a 243 day span OR ~9.88 oz per day for a colony of 45,ooo bees
No all bees are actively contributing to the production cycle of honey (and pollen) though, typically only worker bees of age 14 days and older are working on honey production. During harvest time the average worker life expectancy is 6 weeks (42 days). That gives us a working period of 28 days for the average worker bee during harvest time. Since the colony is almost entirely, 90% to 95%, workers then we can extrapolate that on average we should have ~26,880 worker bees gather honey in a hive of 45,000 bees at any given time.
Thus to derived per bee production
9.88oz / 26,880 bees =0.00037 oz honey produced per bee per day on average.
I will use these calculations as the baseline for the simulation to experiment with colony size and sustainability given different starting configuration and random genetic introductions via Queen mating with random drones.

## Observations
   Due to the inherent nature of the stdlib rand I get large grouping of drones in the simulation that makes the results swing around quite a bit. I need a better controller algorithm or better entropy in my random numbers, or both. 
  I executed the program several time without any random numbering and worked through the math. Bee counts and honey calculation followed my model at that level, but even introducing some randomness into code the lack of entropy may causing more disruption than natural noise. 
  I'm hoping this bee simulator is something I can iterative improve upon over the course of the class as I think it is a good source of heavy data to flex my understanding of data structures and algorithms. 

## Improvements
Upon executing the program with longer time periods it became clear the original implementation of the hives with vectors was resulting in poor performance. The problem resulting from the high growth rate of the honeybees and which results in large reallocation within the vectors of each hive as the vectors grow. I changed the implementation to list and performance was significantly increases as List are best suited for high growth rates and end to end iteration, both of which are exactly what the honeybee simulator is doing as part of the aging algorithm of the hives for each honeybee. 
