 
#include "../../C/UTILITY.H"
#include "../../C/UTILITY.CPP"
typedef char Queue_entry;
#include "../QUEUE/QUEUE.H"
#include "../QUEUE/QUEUE.CPP"
#include "../EXTQUEUE/EXTQUEUE.H"
#include "../EXTQUEUE/EXTQUEUE.CPP"

void introduction();
void help();
char get_command();
bool do_command(char, Extended_queue &);
 
int main()
/* 
 
Post: Accepts commands from user as a menu-driven demonstration program for
the class Extended_queue.
Uses: The class Extended_queue and the
functions introduction, get_command, and do_command.
 
*/
 
{
   Extended_queue test_queue;
   introduction();
   while (do_command(get_command(), test_queue));
}
 
void introduction()
/* 
 
Post: Writes out an introduction and instructions for the user.
 
*/

{
   cout << endl << "\t\tExtended Queue Testing Program" << endl << endl
        << "The program demonstrates an extended queue of " << endl
        << "single character keys. " << endl
        << "Additions occur at the end of the queue, "
        << "while deletions can only be done at the front." << endl
 
        << "The queue can hold a maximum of "
        << maxqueue << " characters." << endl << endl
 
        << "Valid commands are to be entered at each prompt." << endl
        << "Both upper and lower case letters can be used." << endl
        << "At the command prompt press H for help." << endl << endl;
}
 
void help()
/* 
 
Post: A help screen for the program is printed, giving the meaning of each
command that the user may enter.
 
*/


{
   cout << endl
     << "This program allows the user to enter one command" << endl
     << "(but only one) on each input line." << endl
     << "For example, if the command S is entered, then" << endl
     << "the program will serve the front of the queue." << endl
     << endl


     << " The valid commands are:" << endl
     << "A - Append the next input character to the extended queue" << endl
     << "S - Serve the front of the extended queue" << endl
     << "R - Retrieve and print the front entry." << endl
     << "# - The current size of the extended queue" << endl
     << "C - Clear the extended queue (same as delete)" << endl
     << "P - Print the extended queue" << endl
     << "H - This help screen" << endl
     << "Q - Quit" << endl


     << "Press <Enter> to continue." << flush;


   char c;
   do {
      cin.get(c);
   } while (c != '\n');
}
 
char get_command()
/* 
 
Post: Gets a valid command from the user and,
after converting it to lower case if necessary,
returns it.
 */

{
   char c, d;
   cout << "Select command and press <Enter>:" << flush;
   while (true) {
      do {
         cin.get(c);
      } while (c == '\n'); //  c is now a command character.

      do {                 //  Skip remaining characters on the line.
         cin.get(d);
      } while (d != '\n');

      c = tolower(c);
      if (c == 's' || c == '#' || c == 'a' || c == 'c' ||
          c == 'h' || c == 'q' || c == 'p' || c == 'r')
         return c;

      else
         cout << "Please enter a valid command or H for help:"
              << "\n\t[S]erve  entry\t[P]rint queue\t[#] size of queue\n"
              << "\t[C]lear queue\t[R]irst entry\t[A]ppend entry\n"
              << "\t[H]elp\t[Q]uit." << endl;
   }
}
 
bool do_command(char c, Extended_queue &test_queue)
/* 
 
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
 
*/


{
   bool continue_input = true;
   Queue_entry x;

   switch (c) {
   case 'r':
      if (test_queue.retrieve(x) == underflow)
         cout << "Queue is empty." << endl;
      else
         cout << endl
              << "The first entry is: " << x
              << endl;
      break;
 

   case 'q':
      cout << "Extended queue demonstration finished." << endl;
      continue_input = false;
      break;
 
   case 's':
      if (test_queue.serve() == underflow)
         cout << "Serve failed, the Queue is empty." << endl;
      break;
   case 'a':
      if (test_queue.full())
         cout << "Sorry, queue is full." << endl;
      else {
         cout << "Enter new key to insert:" << flush;
         cin.get(x);
         test_queue.append(x);
      }
      break;
   case 'c':
      test_queue.clear();
      cout << "Queue is cleared." << endl;
      break;
   case '#':
      cout << "The size of the queue is " << test_queue.size() << endl;
      break;
   case 'h':
      help();
      break;
   case 'p':
      int sz = test_queue.size();
      if (sz == 0) cout << "Queue is empty." << endl;
      else {
         cout << "\nThe queue contains:\n";
         for (int i = 0; i < sz; i++) {
            test_queue.retrieve(x);
            test_queue.serve();
            test_queue.append(x);
            cout << "  " << x;
         }
         cout << endl;
      }
      break;
 
   //  Additional cases will cover other commands.


   }
   return continue_input;
}
