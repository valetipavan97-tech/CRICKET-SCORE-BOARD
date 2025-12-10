#include <stdio.h>
#include <string.h>

// Define a structure for a cricket player
// This structure holds player details like name, role, and statistics
typedef struct {
    char name[50];        // Player's name
    char role[20];        // Role: batsman, bowler, all-rounder, wicket-keeper, substitute
    int runs;             // Runs scored (for batsmen, all-rounders, wicket-keeper)
    int balls_faced;      // Balls faced (for batsmen, all-rounders, wicket-keeper)
    int wickets;          // Wickets taken (for bowlers, all-rounders)
    int overs_bowled;     // Overs bowled (for bowlers, all-rounders)
    int runs_conceded;    // Runs conceded (for bowlers, all-rounders)
} Player;

// Function to display the cricket scoreboard for a given team
// This function prints the current state of the match for the specified team, including total score, batsmen, and bowlers
void displayScoreboard(Player players[], int num_players, int total_runs, int wickets, int overs, int balls, char team_name[]) {
    printf("\n=== %s Cricket Scoreboard ===\n", team_name);
    printf("Total Score: %d/%d in %d.%d overs\n\n", total_runs, wickets, overs, balls);
    
    // Display batsmen (including wicket-keeper and all-rounders who bat)
    printf("Batsmen:\n");
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].role, "batsman") == 0 || 
            strcmp(players[i].role, "wicket-keeper") == 0 || 
            strcmp(players[i].role, "all-rounder") == 0) {
            printf("  %s: %d runs (%d balls)\n", players[i].name, players[i].runs, players[i].balls_faced);
        }
    }
    
    // Display bowlers (including all-rounders who bowl)
    printf("\nBowlers:\n");
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].role, "bowler") == 0 || strcmp(players[i].role, "all-rounder") == 0) {
            printf("  %s: %d wickets for %d runs in %d overs\n", 
                   players[i].name, players[i].wickets, players[i].runs_conceded, players[i].overs_bowled);
        }
    }
    
    // Substitutes are not displayed as they are not actively playing
    printf("\n(Note: Substitutes are available but not currently in play.)\n");
}

int main() {
    // Define Team A with 4 batsmen, 4 bowlers, 2 all-rounders, 1 wicket-keeper, and 2 substitutes
    Player teamA[13] = {
        {"TeamA_Batsman1", "batsman", 0, 0, 0, 0, 0},
        {"TeamA_Batsman2", "batsman", 0, 0, 0, 0, 0},
        {"TeamA_Batsman3", "batsman", 0, 0, 0, 0, 0},
        {"TeamA_Batsman4", "batsman", 0, 0, 0, 0, 0},
        {"TeamA_Bowler1", "bowler", 0, 0, 0, 0, 0},
        {"TeamA_Bowler2", "bowler", 0, 0, 0, 0, 0},
        {"TeamA_Bowler3", "bowler", 0, 0, 0, 0, 0},
        {"TeamA_Bowler4", "bowler", 0, 0, 0, 0, 0},
        {"TeamA_AllRounder1", "all-rounder", 0, 0, 0, 0, 0},
        {"TeamA_AllRounder2", "all-rounder", 0, 0, 0, 0, 0},
        {"TeamA_WicketKeeper", "wicket-keeper", 0, 0, 0, 0, 0},
        {"TeamA_Substitute1", "substitute", 0, 0, 0, 0, 0},
        {"TeamA_Substitute2", "substitute", 0, 0, 0, 0, 0}
    };
    
    // Define Team B with 4 batsmen, 4 bowlers, 2 all-rounders, 1 wicket-keeper, and 2 substitutes
    Player teamB[13] = {
        {"TeamB_Batsman1", "batsman", 0, 0, 0, 0, 0},
        {"TeamB_Batsman2", "batsman", 0, 0, 0, 0, 0},
        {"TeamB_Batsman3", "batsman", 0, 0, 0, 0, 0},
        {"TeamB_Batsman4", "batsman", 0, 0, 0, 0, 0},
        {"TeamB_Bowler1", "bowler", 0, 0, 0, 0, 0},
        {"TeamB_Bowler2", "bowler", 0, 0, 0, 0, 0},
        {"TeamB_Bowler3", "bowler", 0, 0, 0, 0, 0},
        {"TeamB_Bowler4", "bowler", 0, 0, 0, 0, 0},
        {"TeamB_AllRounder1", "all-rounder", 0, 0, 0, 0, 0},
        {"TeamB_AllRounder2", "all-rounder", 0, 0, 0, 0, 0},
        {"TeamB_WicketKeeper", "wicket-keeper", 0, 0, 0, 0, 0},
        {"TeamB_Substitute1", "substitute", 0, 0, 0, 0, 0},
        {"TeamB_Substitute2", "substitute", 0, 0, 0, 0, 0}
    };
    
    // Initialize match variables for Team A (batting first)
    int total_runs_A = 0;    // Total runs scored by Team A
    int wickets_A = 0;       // Number of wickets fallen for Team A
    int overs_A = 0;         // Number of overs completed for Team A
    int balls_A = 0;         // Balls bowled in the current over for Team A (0-5)
    
    // Initialize match variables for Team B (batting second)
    int total_runs_B = 0;    // Total runs scored by Team B
    int wickets_B = 0;       // Number of wickets fallen for Team B
    int overs_B = 0;         // Number of overs completed for Team B
    int balls_B = 0;         // Balls bowled in the current over for Team B (0-5)
    
    // Simulate some match events for Team A (batting first)
    // Example: TeamA_Batsman1 scores 50 runs in 40 balls
    teamA[0].runs = 50;
    teamA[0].balls_faced = 40;
    total_runs_A += 50;
    
    // Example: A wicket falls for Team A (e.g., TeamA_Batsman2 out)
    wickets_A++;
    
    // Example: TeamA_Bowler1 takes 1 wicket, concedes 30 runs in 4 overs (while bowling against Team B)
    teamA[4].wickets = 1;
    teamA[4].runs_conceded = 30;
    teamA[4].overs_bowled = 4;
    
    // Example: TeamA_AllRounder1 scores 25 runs in 20 balls and takes 2 wickets, concedes 40 in 5 overs
    teamA[8].runs = 25;
    teamA[8].balls_faced = 20;
    teamA[8].wickets = 2;
    teamA[8].runs_conceded = 40;
    teamA[8].overs_bowled = 5;
    total_runs_A += 25;
    
    // Update Team A's innings progress (e.g., 10 overs completed)
    overs_A = 10;
    balls_A = 0;
    
    // Simulate some match events for Team B (batting second)
    // Example: TeamB_Batsman1 scores 45 runs in 35 balls
    teamB[0].runs = 45;
    teamB[0].balls_faced = 35;
    total_runs_B += 45;
    
    // Example: A wicket falls for Team B (e.g., TeamB_Batsman2 out)
    wickets_B++;
    
    // Example: TeamB_Bowler1 takes 1 wicket, concedes 25 runs in 3 overs (while bowling against Team A)
    teamB[4].wickets = 1;
    teamB[4].runs_conceded = 25;
    teamB[4].overs_bowled = 3;
    
    // Example: TeamB_AllRounder1 scores 30 runs in 25 balls and takes 1 wicket, concedes 35 in 4 overs
    teamB[8].runs = 30;
    teamB[8].balls_faced = 25;
    teamB[8].wickets = 1;
    teamB[8].runs_conceded = 35;
    teamB[8].overs_bowled = 4;
    total_runs_B += 30;
    
    // Update Team B's innings progress (e.g., 8 overs completed)
    overs_B = 8;
    balls_B = 2;  // Example: 2 balls into the 9th over
    
    // Display the scoreboards for both teams
    displayScoreboard(teamA, 13, total_runs_A, wickets_A, overs_A, balls_A, "Team A");
    displayScoreboard(teamB, 13, total_runs_B, wickets_B, overs_B, balls_B, "Team B");
    
    // In a real program, you could add loops for user input to update scores interactively
    // For example, prompt for runs scored, wickets, etc., and update accordingly
    // You could also add logic to determine the winner based on scores
    
    return 0;
}
