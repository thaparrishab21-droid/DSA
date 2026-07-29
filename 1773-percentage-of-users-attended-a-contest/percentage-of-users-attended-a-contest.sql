# Write your MySQL query statement below
select r.contest_id,round(100*count(r.user_id)/(SELECT COUNT(*) FROM Users),2) as percentage
from Register r
left join Users u
on u.user_id=r.user_id
group by r.contest_id
order by percentage desc, r.contest_id asc;