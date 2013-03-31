###This is a Test App for HTTPS support in openFrameworks. 
I like using test apps when debugging a defect/bug and sometimes its easier to show a problem to someone else than 
to describe it.  Also if someone else wants to look at the issue because they know what is wrong and how to fix it
they can quickly grab this project and code away. This won't win any points for being elegant but it.


What it does:

     1) loads a https url and http url using the ofLoadURLAsync functions
         a) urlResponse is setup to listen for both responses
     2) loads a https url and http url using the ofLoadURL function
     3) displays the returned JSON on the screen, instagram for https and flickr for http


What happens:
 
     1) The http calls return successfully and render json
     2) The ofLoadURL call using the https url returns blank
     3) The ofLoadURLAsync call using the https url never gets updated
     4) The terminal prints : [error] ofURLFileLoader No message received
     5) The error message from urlResponse shows -1 as the status

What should happen:

     1)Load both http and https urls via ofLoadURLAsync
     2)Load both http and https urls via ofLoadURL
     3)Render the JSON returned from the http url  (flickr)
     4)Render the JSON returned from the https url (instagram)
