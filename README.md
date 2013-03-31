This is a Test App that tests HTTPS support in openFrameworks. 
I like using test apps when debugging a defect/bug and sometimes its easier to show a problem to someone else than to describe it.
Also other people can grab this and fix it if they know what is borked and how to fix it faster than I can.

This won't win any points for being elegant.  


What it does:

 1) loads a https url and http url using the ofLoadURLAsync function
     a) urlResponse is setup to listen for both responses
 2) loads a https url and http url using the ofLoadURL function 


What happens:
 
 1) The http calls return successfully and render json
 2) The ofLoadURL call using the https url returns blank
 3) The ofLoadURLAsync call using the https url never gets updated
 4) The terminal prints : [error] ofURLFileLoader No message received
 5) The error message from urlResponse shows -1 as the status

What should happen:
 1)Load both http and https urls via ofLoadURLAsync
 2)Load both http and https urls via ofLoadURL
 3)Render the JSON from the http web service  (flickr)
 4)Render the JSON from the https web service (instagram)



