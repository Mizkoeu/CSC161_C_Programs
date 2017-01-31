    /***********************************************************************
     * Name(s)  (identify both lab partners for labs, projects)            *
     * Box(s):                                                             *
     * Assignment name (Lab, Project, Sup. Problem Number _______)         *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <due date>                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     [include textbook(s), CSC 161 labs or readings;                 *
     *       complete citations for Web or other written sources           *
     *      write "none" if no sources used]                               *
     *   Help obtained                                                     *
     *     [indicate names of instructor, class mentors                    *
     *      or evening tutors, consulted according to class policy;        *
     *      write "none" if none of these sources used]                    *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/



// 2. Write second function
// a) Using Scheme like functions like car and cdr:





// b) using C syntax:

char * second (listType list) {
  if (list == NULL) {
    return NULL;
  }
  else if (list->next == NULL) {
    return NULL;
  }
  else          
  return (list->next)->data;
}



// 3. Write count function
// a) Using Scheme like functions like car and cdr:
int count1 (listType list, char * item) {
  int counter = 0;
  while (list != NULL)
    {
      if (strcmp (car (list), item) == 0)
        { counter++;
          list = cdr (list);
        }
      else
        list = cdr (list);
    }
  return counter;
}

// b) using C syntax:
int count2 (listType list, char * item) {
  int count = 0;
  while (list != NULL)
    {
      if (strcmp (list->data, item) == 0)
        { count++;
          list = list->next;
        }
      else
        list = list->next;      
    }
  return count;
}


/* 4. 
(a) When c is printed immediately after the statement listdelete (&d),
the output is random symbols (different symbols everytime we ran it).

(b) This is because the command listDelete only deallocates the nodes 
a, b, c, d, e.



/* 5. Write last function */
// a) Using Scheme like functions like car and cdr:


char * last1 (listType list)
{
  if (list == NULL)
    return NULL;
  else
    {
      { while (cdr (list) != NULL)
          list = cdr (list);
      }  
      return car (list);
    }
}


/* code segment in main that calls the function */

char * end1 = last1 (d); // d is defined previously as a listType
printf ("The last element in the list is %s\n", end1);

// b) using C syntax:

char * last2 (listType list)
{ if (list == NULL)
    return NULL;
  else
    {
      { while ((list -> next) != NULL)
          list = list -> next;
      }
      return list -> data;
    }
 }

/* code segment in main that calls the function */
char * end2 = last2 (d); // d is defined previously as a listType
printf ("The last element in the list is %s\n", end2);

// 6. Write getIndex function;
// a) Using Scheme like functions like car and cdr:
int getIndex1 (listType list, char * target_str)
{ int counter = 0;
  if ( list == NULL)
    return -1;
  while (list != NULL)
    { if ( strcmp (car (list), target_str) == 0 )
        return counter;
      else
        { counter ++;
          list = cdr (list);
        }      
        
    }
  return -1; // if within the while loop, we did not find the target string, that is, if there is no target string in the list, return -1.
}

/* code segment in main that calls the function */
int index;
index = getIndex1 (d, "node B");
printf ("The index is %d\n", index);
  

// b) using C syntax:


int getIndex2 (listType list, char * target_str)
{ int counter = 0;
  
  if ( list == NULL)
    return -1;
  while (list != NULL)
    { if ( strcmp (list -> data, target_str) == 0 )
        return counter;
      else
        { counter ++;
          list = list -> next;
        }      
        
    }
    return -1;
}


/* code segment in main that calls the function */
  int index;
  index = getIndex2 (d, "node B");
  printf ("The index is %d", index);
