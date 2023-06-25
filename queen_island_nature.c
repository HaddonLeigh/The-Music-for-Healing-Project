#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Flag to indicate whether the program is running
bool isRunning = true;

// Struct that contains the data for a single music therapy session
struct music_therapy_session {
    char type[20];                   // Therapy type (e.g. relaxation or cognitive)
    int duration;                    // Length of the session
    char therapist[20];              // Name of the therapist
    char techniques[20];             // Techniques used during the session
    char patient_response[20];       // Patient's response
};

// Function prototypes
void printMenu(void);                                 // Prints the main menu
struct music_therapy_session createNewSession(void);   // Creates a new music therapy session
void deleteSession(struct music_therapy_session *);    // Deletes a music therapy session
void viewSessions(struct music_therapy_session *);    // Views existing music therapy sessions
void editSession(struct music_therapy_session *);     // Edits an existing music therapy session
void exitProgram(void);                               // Exits the program

// Main function
int main(void) {
    printf("Welcome to the Music Therapy Program\n\n");

    // Array of music therapy sessions
    struct music_therapy_session sessions[100];
    int session_count = 0;

    // Main loop
    while (isRunning) {
        printMenu();
        int selection;
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                sessions[session_count] = createNewSession();
                session_count++;
                break;
            case 2:
                if (session_count == 0) {
                    printf("No sessions to delete\n\n");
                } else {
                    deleteSession(&sessions[session_count-1]);
                    session_count--;
                }
                break;
            case 3:
                viewSessions(&sessions[0]);
                break;
            case 4:
                if (session_count == 0) {
                    printf("No sessions to edit\n\n");
                } else {
                    editSession(&sessions[session_count-1]);
                }
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid selection\n\n");
                break;
        }
    }
    
    return 0;
}

// Prints the main menu
void printMenu(void) {
    printf("Main Menu\n");
    printf("1) Create new session\n");
    printf("2) Delete session\n");
    printf("3) View sessions\n");
    printf("4) Edit session\n");
    printf("5) Exit program\n\n");
    printf("Enter selection: ");
}

// Creates a new music therapy session
struct music_therapy_session createNewSession(void) {
    // Create a new music therapy session
    struct music_therapy_session session;

    // Get user input
    printf("Type of therapy: ");
    scanf("%s", session.type);
    printf("Duration of session (in minutes): ");
    scanf("%d", &session.duration);
    printf("Name of the therapist: ");
    scanf("%s", session.therapist);
    printf("Techniques used during the session: ");
    scanf("%s", session.techniques);
    printf("Patient's response: ");
    scanf("%s", session.patient_response);

    printf("Session created\n\n");

    return session;
}

// Deletes a music therapy session
void deleteSession(struct music_therapy_session *session) {
    session->type[0] = '\0';
    session->duration = 0;
    session->therapist[0] = '\0';
    session->techniques[0] = '\0';
    session->patient_response[0] = '\0';

    printf("Session deleted\n\n");
}

// Views existing music therapy sessions
void viewSessions(struct music_therapy_session *sessions) {
    for (int i = 0; i < 100; i++) {
        if (strlen(sessions[i].type) > 0) {
            printf("Type of Therapy: %s\n", sessions[i].type);
            printf("Duration of Session: %d minutes\n", sessions[i].duration);
            printf("Name of the Therapist: %s\n", sessions[i].therapist);
            printf("Techniques Used: %s\n", sessions[i].techniques);
            printf("Patient's Response: %s\n\n", sessions[i].patient_response);
        }
    }
}

// Edits an existing music therapy session
void editSession(struct music_therapy_session *session) {
    printf("Type of therapy: ");
    scanf("%s", session->type);
    printf("Duration of session (in minutes): ");
    scanf("%d", &session->duration);
    printf("Name of the therapist: ");
    scanf("%s", session->therapist);
    printf("Techniques used during the session: ");
    scanf("%s", session->techniques);
    printf("Patient's response: ");
    scanf("%s", session->patient_response);

    printf("Session edited\n\n");
}

// Exits the program
void exitProgram(void) {
    printf("Exiting program...\n");
    isRunning = false;
}