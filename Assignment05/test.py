import math

timestamp=sum([
    #2000,#sec
    #31*86400,#day
    4000*365.25*86400,#years
])

year=math.floor(timestamp/31556926+1970)
date=timestamp/86400%30



dayOfWeek="thu fri sat sun mon tue wed".split()[
    math.floor((timestamp/86400)%7)
].upper()
month=["jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"][
    math.floor(timestamp/2678400%12)
].upper()
print(year,dayOfWeek)
