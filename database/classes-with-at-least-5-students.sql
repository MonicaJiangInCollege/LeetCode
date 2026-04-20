# Write your MySQL query statement below
select class
from Courses
where count(student)>=5;