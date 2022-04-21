// Sean Peters
//4/19/2022
//OS Assignment 2: Bankers Algorithm



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//contains the data 
struct theData 
{
    uint32_t theAllocated;

    uint32_t theMax;
    uint32_t theNeeded;
};

// tracks the data
struct theTracker 
{
    std::vector<theData> Vect;
    bool sequenced;
};



int main()
{
    std::vector<uint32_t> available;
    std::vector<theTracker> processes;
       

    bool DataInput(const char* theFilename, std::vector<uint32_t > &isAvailable, std::vector<theTracker > &theProcesses);

    if (!DataInput("Data.txt", available, processes))
    {
        std::cout << "File Error";
        return -1;
    }

    // Calculate need
    // For all processes...
    for (auto a = processes.begin(); a != processes.end(); a++)
        for (auto b = a -> Vect.begin(); b != a -> Vect.end(); b++)
            b -> theNeeded = b -> theMax - b -> theAllocated; 
    

    
    std::vector<uint32_t> NonCorruptSeq;

    
    // while loop that iterats though the sequences until there is a safe one found 
    while (NonCorruptSeq.size() < processes.size())
    {
        bool ProcProg = false;

        for (uint32_t newProcess = 0; newProcess < processes.size(); newProcess++)
        {
            auto& a = processes[newProcess];
           
            bool safeBool = true;

            for (uint32_t resIdx = 0; resIdx < a.Vect.size(); resIdx++)
            {
                if (a.Vect[resIdx].theNeeded > available[resIdx])
                {
                    safeBool = false;
                    break;
                }
            }

            if (a.sequenced)
                continue; 

            if (!safeBool)
                continue; 

            
            a.sequenced = true;
           
            NonCorruptSeq.push_back(newProcess);

            // for when the process is finnished
            for (uint32_t dataID = 0; dataID < a.Vect.size(); dataID++)
                available[dataID] += a.Vect[dataID].theAllocated;

            ProcProg = true;
        }

    }
    std::string theSafeSeqStr;


    if (processes.size() != NonCorruptSeq.size())
        std::cout << "The state is unsafe" << std::endl;
    
    else
    {
        std::cout << "The safe sequence would be: " << std::endl;
        for (auto it = NonCorruptSeq.begin(); it != NonCorruptSeq.end(); it++)
        {
            theSafeSeqStr += std::string("P") + std::to_string(*it);

            if ((NonCorruptSeq.end() - 1) != it)
                theSafeSeqStr += " > ";
        }
        std::cout << theSafeSeqStr << std::endl;
    }
    return 0;
}

bool DataInput(const char* thefilename, std::vector<uint32_t>& isAvailable, std::vector<theTracker>& theProcesses)
{
    try 
    {
        std::ifstream theFile(thefilename);

        std::vector<std::string> theLines;
 
            std::string str;
            while(std::getline(theFile, str))
             
                  if (!str.empty())
                       theLines.push_back(str);
              

        

        {
            std::stringstream theStr(theLines[0]);

            for (std::string value; std::getline(theStr, value, ',');) 
                isAvailable.push_back(std::stoi(value));
            
        }

       
        for (auto lineIt = theLines.begin() + 1; theLines.end()!= lineIt; lineIt++)
        {
            theTracker thisProcess{};

          

            uint32_t isAllocated;
            uint32_t theID = 0;

            std::stringstream ss(*lineIt);
            for (std::string value; std::getline(ss, value, ','); )
            {
                if (theID != 0) // this is to read in the allocated values
                {

                    uint32_t max = std::stoi(value);

                    thisProcess.Vect.push_back
                        ({ 
                            isAllocated, max, 0 
                        });

                    theID = 0; // either we are done with the line or next is allocated


                }
                else 
                {
                    ++theID; 
                    isAllocated = std::stoi(value);
                   
                }
            }
            

            theProcesses.emplace_back(std::move(thisProcess));
        }
    }

    catch (...)
    {
        return false;
    }

    return true;
}
