# Write your MySQL query statement below
select class
from Courses
group by class
where count(student)>=5;