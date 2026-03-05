from Queue import PriorityQueue

class Solution(object):
    def binarySearch(self, val, array):
        i = 0
        j = len(array) - 1
        
        while ( i <= j):
            mid = i + (j - i) /2
            
            if array[mid] > val and (mid == 0 or array[mid - 1] <= val):
                return mid
            
            if array[mid] > val:
                j = mid - 1
            else:
                i = mid + 1
        return None
            
    def avoidFlood(self, rains):
        
        lakeRain = dict()
        dryDays = []
        result = []

        for day, lake in enumerate(rains):
            if lake == 0:
                dryDays.append(day)
                result.append(1)
            else:
                if lake not in lakeRain:
                    lakeRain[lake] = day
                    result.append(-1)
                else:
                    result.append(-1)
                    chosenDay = None
                    previousRainDay = lakeRain[lake]
                    
                    chosenDayIndex = self.binarySearch(previousRainDay, dryDays)
                    
                    if chosenDayIndex is None:
                        return []
                    else:
                        dryDay = dryDays[chosenDayIndex]
                        dryDays.pop(chosenDayIndex)
                        lakeRain[lake] = day
                        result[dryDay] = lake
        return result