**Summarize the project and what problem it was solving.**
  This program is a grocery list application that assists a grocery store in analyzing the quantities of items they sell in order to provide a more efficient store layout to         customers. The user interface offers three options for the application:
    Return the items from a file with the day's sales along with each item's quantity sold without duplicate items.
    Find a specific item within the file and return its quantity sold.
    Display a histogram of the items sold and their quantities for a more easily viewable representation of item consumption by customers.
    
**What did you do particularly well?**
  The program user display is clean and efficient. The focus was toward providing on the information requested by the user for analysis without excess clutter when outputted. The   program is also easily readable and would be easily maintained due to the way each function is used. The main function has minimal code and the majority of data analysis and       file manipulation are done using Python, which makes updating the code without prior knowledge more practical.
  
**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**
  I could look for areas to increase error handling. User inputs can be better controlled to require valid inputs after the initial option selection. This would avoid unnecesary     failures related to things like a user mistakenly inputting an integer where a string is expected in one of the functions. I could allow the user to provide the name of the file   that is created to display the histogram and allowed the file to not be removed after the program exits. This wouldn't make the program more efficient necessarily, but it would   offer some expanded functionality.

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**
  I found the output of the histogram most difficult because I originally had issues with a duplicate value at the end of the file. Stack Overflow provided an explanation of why     the file was returning a duplicate value, and I realized I needed to base the loop on the data values existing in each line to properly exit the loop.

**What skills from this project will be particularly transferable to other projects or course work?**
  The integration of multiple programming languages together is probably the most useful skill I've developed from this project. I came to realize there are certainly aspects of a   program that are better suited to a certain language than another. Python in this instance was better served for file input/output than C++ and utilizing it helped develop the     program in a more clear and concise manner.

**How did you make this program maintainable, readable, and adaptable?**
  The program has numerous comments that detail the areas that may not be as intutitive at first. The formatting also maintains proper naming conventions and spacing standards so   it appears more organized. Additionally, the program operates using functions in Python that carry out the bulk of the file operations and data analysis loops. This is an         advantage for readability, maintainability, and adaptability, because each function can be updated as the program requires and new functions can be added easily without changing   the flow of the program.
