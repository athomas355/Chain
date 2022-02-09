Chain Program

What it does:   

How to use it:
    chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile

OPTIONS:
    -h          Help message 
    -p      
        nprocs: Number of processes [default 4]
    -c 
        nchars: Number of characters read into the buffer [default 80]
    -s 
        sleeptime: Time to sleep in each iteration [default 3s]
    -i 
        niters: Numbner of iterations in the loop
    textfile    File containing text to be read through stdin

Observations:
    1. 
        -for 4 processes pid starts at 7584 and it increments up to 7587. pid 7586 has a parent id of 1 suggesting it is an orphan
        -10 processes start at pid 7648 increments by 1 to 7657. All processes besides first and last are orphaned
        -100 processes also same pids increment by 1. Processes were split up between being orphaned and not orphaned.
    
    2. Figure 3.2 redraw
        -1. pid: 7584
        -2. pid: 7585
        -3. pid: 7586
        -4. pid: 7587 
    
    3. 
        -I would say about 20% were orphaned the others didn't have their parent ID's as 1

    4. sleep(10)
        -almost all processes are orphans since their parents probably terminated.
        -it all incremented the same except the last two iteration 99 came after iteration 100. It went 98, 100, 99.

    5. for loop with k and m
        p = 4, k = 3, m = 10 
            -pids are repeated every iteration     
            -most processes were not orphaned except last 2
            -the first iteration had different order of process it went: 8621, 8622, 8624, 8623. Then after this it incremented normally
        p = 10, k = 4, m = 5
            -processes are reused every iteration
            -every iteration except the last had no orphans. The last iteration all but one process was orphaned 
        p = 100, k = 2, m = 3
            -processes reused 
            -last iteration seems to be orphaned in most test cases

    6. 
        -no process was orphaned  
        -seems the wait causes the pids to go in the reverse order so it looks like it is decrementing from 9352 to 9253. However its probably not decrementing from what it looks like I think it just is outputed in the reverse order or basically upside-down
    
    7. 
        -not much different from step 6 output

    8. 
        -An iteration goes through nchar characters and then the next iteration takes over from where the last iteration stopped at
        
Problems:
    -had some problems understanding step 8
    -had error message that read "*** stack smashing detected ***: terminated"
        -didn't know what this was but was able to get it to work by understanding how to make the loop in step 8 better
    