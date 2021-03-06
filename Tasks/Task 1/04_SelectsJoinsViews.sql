USE PhoneBook
GO

IF EXISTS (SELECT 1 FROM sys.views WHERE Name = 'PERSONS_WITH_NOKIAS')
	DROP VIEW PERSONS_WITH_NOKIAS
GO
IF EXISTS (SELECT 1 FROM sys.views WHERE Name = 'PERSONS_FROM_SOFIA_PLOVDIV_VARNA')
	DROP VIEW PERSONS_FROM_SOFIA_PLOVDIV_VARNA
GO
IF EXISTS (SELECT 1 FROM sys.views WHERE Name = 'ALL_CITIES')
	DROP VIEW ALL_CITIES
GO
IF EXISTS (SELECT 1 FROM sys.views WHERE Name = 'ALL_PERSONS')
	DROP VIEW ALL_PERSONS
GO
IF EXISTS (SELECT 1 FROM sys.views WHERE Name = 'PERSONS_WITH_HOME_PHONE_TYPE_FROM_VARNA_RUSE')
	DROP VIEW PERSONS_WITH_HOME_PHONE_TYPE_FROM_VARNA_RUSE
GO

CREATE VIEW ALL_CITIES AS
	 SELECT FIRST_NAME, LAST_NAME, CITY_NAME
	 FROM PERSONS
	 RIGHT JOIN CITIES
		ON CITIES.ID = PERSONS.ID
GO

CREATE VIEW ALL_PERSONS AS
	SELECT FIRST_NAME, LAST_NAME, NUMBER, PHONE_TYPE
	FROM PERSONS AS p
	LEFT JOIN PHONE_NUMBERS AS pn
		ON p.ID = pn.PERSON_ID
	LEFT JOIN PHONE_TYPES AS pt
		ON pt.ID = pn.PHONE_TYPE_ID
GO

CREATE VIEW PERSONS_WITH_NOKIAS AS
SELECT FIRST_NAME, LAST_NAME, CITY_NAME, PHONE_TYPE
	FROM PERSONS AS p
	INNER JOIN CITIES AS c
		ON p.CITY_ID = c.ID
	INNER JOIN PHONE_NUMBERS AS pn
		ON pn.PERSON_ID = p.ID
	INNER JOIN PHONE_TYPES AS pt
		ON pt.ID = pn.PHONE_TYPE_ID
	WHERE LEFT(PHONE_TYPE, 5) = 'Nokia'
GO

CREATE VIEW PERSONS_FROM_SOFIA_PLOVDIV_VARNA AS
	SELECT FIRST_NAME, LAST_NAME, ADDRESS, CITY_NAME
	FROM PERSONS 
	INNER JOIN CITIES 
		ON PERSONS.CITY_ID = CITIES.ID
	WHERE CITY_NAME = 'Sofia' OR CITY_NAME = 'Varna' OR CITY_NAME = 'Plovdiv'
GO

CREATE VIEW PERSONS_WITH_HOME_PHONE_TYPE_FROM_VARNA_RUSE AS
	SELECT FIRST_NAME, LAST_NAME, PHONE_TYPE, CITY_NAME, NUMBER
	FROM PERSONS AS p
	INNER JOIN CITIES AS c
		ON p.CITY_ID = c.ID
	INNER JOIN PHONE_NUMBERS AS pn
		ON pn.PERSON_ID = p.ID
	INNER JOIN PHONE_TYPES AS pt
		ON pt.ID = pn.PHONE_TYPE_ID
	WHERE (CITY_NAME = 'Varna' OR CITY_NAME = 'Ruse') AND LEFT(PHONE_TYPE, 5) = 'Home'
GO

--PERSONS without NUMBER
SELECT FIRST_NAME, LAST_NAME, NUMBER
FROM PERSONS 
LEFT JOIN PHONE_NUMBERS
	ON PHONE_NUMBERS.PERSON_ID = PERSONS.ID
WHERE NUMBER IS NULL

SELECT * FROM ALL_CITIES ORDER BY CITY_NAME
SELECT * FROM ALL_PERSONS ORDER BY FIRST_NAME ASC, LAST_NAME ASC
SELECT * FROM PERSONS_FROM_SOFIA_PLOVDIV_VARNA ORDER BY FIRST_NAME ASC, LAST_NAME ASC
SELECT * FROM PERSONS_WITH_NOKIAS ORDER BY PHONE_TYPE ASC
SELECT * FROM PERSONS_WITH_HOME_PHONE_TYPE_FROM_VARNA_RUSE ORDER BY CITY_NAME ASC
GO