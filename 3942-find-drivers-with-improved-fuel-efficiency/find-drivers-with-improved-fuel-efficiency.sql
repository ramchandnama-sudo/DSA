# Write your MySQL query statement below
WITH first_half AS
(SELECT 
    d.driver_id, 
    d.driver_name,
    t.trip_date, 
    AVG(t.distance_km / t.fuel_consumed) AS first_half_avg 
FROM drivers d
JOIN trips t
ON d.driver_id = t.driver_id
WHERE t.trip_date between '2023-01-01' and '2023-06-30'
GROUP BY d.driver_id, d.driver_name),

second_half AS
(SELECT 
    d.driver_id, 
    d.driver_name,
    t.trip_date, 
    AVG(t.distance_km / t.fuel_consumed) AS second_half_avg
FROM drivers d
JOIN trips t
ON d.driver_id = t.driver_id
WHERE t.trip_date between '2023-07-01' and '2023-12-31'
GROUP BY d.driver_id, d.driver_name)

SELECT 
  f.driver_id, 
  f.driver_name, 
  ROUND(first_half_avg,2) first_half_avg , 
  ROUND(second_half_avg,2) second_half_avg, 
  ROUND(second_half_avg - first_half_avg,2) AS efficiency_improvement
FROM first_half f
JOIN second_half s
ON f.driver_id = s.driver_id
WHERE second_half_avg - first_half_avg > 0
ORDER BY efficiency_improvement desc, f.driver_name