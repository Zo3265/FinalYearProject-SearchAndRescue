# How to Run  
1. Make sue you have Unreal Engine 5.5.4 installed.
2. Clone to your PC using Github Desktop (or the command line if you know how to).
3. Go from FinalYearProject-SearchAndRescue -> SearchAndRescue.
4. Right click SearchAndRescue.uproject then click "Generate visual studio project files". Wait for a progress bar to show up and finish. (This can take some time).
5. Double click "SearchAndRescue.sln".
6. Once in, look at the top of the application and click on the "build" section. This will give you a dropdown list of actions.
7. Click on the one that says "Rebuild Solution" and wait. This can take some time.
8. Once it is done the file paths have been changed to be specific to your machine you can now double click on SearchAndRescue.uproject to open the project.
9. By default you will load into the Machine Learning agents training map.
10. If you want to go to a different map go to Content -> FirstPerson -> Maps. There you will find all the maps that are used both for training and the main game.

# Change to Training Mode
By default the M.L agents are left in inference mode. I DON'T RECOMMEND THIS but if you want to go back into training mode do the following:  
1. Go to the BP_Manager blueprint in the MLAI folder and click into it.
2. Look for a boolean called "RunInference" and uncheck it.
3. Then go into the header files for the following classes - EnemyInteractor, EnemyTainingEnvironment and BulletBase.
4. Set the boolean "bTraining" to false for each of the header files. Then compile the code.
5. You can now train the agents some more but be WARNED YOU MAY BREAK THEIR BEHAVIOUR.
