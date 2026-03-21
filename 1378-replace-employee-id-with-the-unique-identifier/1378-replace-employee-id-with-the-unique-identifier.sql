SELECT  b.unique_id ,a.name 
FROM Employees as a
LEFT JOIN EmployeeUNI as b
on a.id=b.id ;