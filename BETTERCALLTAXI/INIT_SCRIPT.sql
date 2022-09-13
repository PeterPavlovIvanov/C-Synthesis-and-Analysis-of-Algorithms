USE [master]
GO

IF NOT EXISTS (SELECT * FROM sys.databases WITH(NOLOCK) WHERE NAME = 'BETTERCALLTAXI')
BEGIN
	CREATE DATABASE [BetterCallTaxi]
END
GO

USE BetterCallTaxi
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'ROLES')
BEGIN
	CREATE TABLE ROLES
	(
		  ID	INT IDENTITY(1, 1)	NOT NULL /* 1 - RoleAdministrator; 2 - RoleDriver; 3 - RoleUser; */
		, ROLE	VARCHAR(15)			NOT NULL DEFAULT 'User'
	)
	
	ALTER TABLE ROLES
	ADD CONSTRAINT PK_ROLES_REQUESTS_ID PRIMARY KEY (ID)

	INSERT INTO ROLES
	VALUES
	  ('Administrator')
	, ('Driver')
	, ('User')
END 
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'CUSTOMERS')
BEGIN
	CREATE TABLE CUSTOMERS
	(
		  ID			INT IDENTITY(1, 1)	NOT NULL			
		, UCN			CHAR(10)			NOT NULL			
		, NAME			VARCHAR(60)			NOT NULL			
		, ORDERS_MADE	INT					NOT NULL DEFAULT 0	
		, ROLE_ID		INT					NOT NULL DEFAULT 3
		, USERNAME		VARCHAR(60)			NOT NULL 
		, PASSWORD		BINARY(64)			NOT NULL
	)
	
	ALTER TABLE CUSTOMERS
	ADD CONSTRAINT PK_CUSTOMERS_ID PRIMARY KEY (ID)

	ALTER TABLE CUSTOMERS
	ADD FOREIGN KEY (ROLE_ID) REFERENCES ROLES(ID)

	CREATE UNIQUE INDEX UX_CUSTOMERS_UCN
	ON CUSTOMERS (UCN)

	CREATE UNIQUE INDEX UX_CUSTOMERS_USERNAME
	ON CUSTOMERS (USERNAME)

	INSERT INTO CUSTOMERS
	VALUES
		  (	'8723849312', 'Taylah Mullen'		, 0, 2, 'Taylah123',		HASHBYTES('SHA2_512', '123456'))
		, (	'9482034921', 'Radhika Bate'		, 1, 3, 'Radhika34',		HASHBYTES('SHA2_512', '123456'))
		, (	'8209312934', 'Aditya Pope'			, 1, 3, '432Aditya',		HASHBYTES('SHA2_512', '123456'))
		, (	'9103239412', 'Mindy Joyce'			, 1, 1, 'Mindy42',			HASHBYTES('SHA2_512', '123456'))
		, (	'8793012034', 'Christina Farley'	, 2, 3, 'Christina6',		HASHBYTES('SHA2_512', '123456'))
		, (	'9348239401', 'Conna Burch'			, 3, 3, 'Conna2',			HASHBYTES('SHA2_512', '123456'))
		, (	'0012934813', 'Alina Pacheco'		, 1, 3, 'Alina',			HASHBYTES('SHA2_512', '123456'))
		, (	'9982839102', 'Tomi Charles'		, 2, 3, 'Tomi44',			HASHBYTES('SHA2_512', '123456'))
		, (	'9738291382', 'Arandeep Compton'	, 0, 2, 'ArandeepXASD',		HASHBYTES('SHA2_512', '123456'))
		, (	'9121283109', 'Valentina Tillman'	, 2, 3, 'Valentina31',		HASHBYTES('SHA2_512', '123456'))
		, (	'0031231098', 'Finnian Henderson'	, 0, 2, '34Finnian3',		HASHBYTES('SHA2_512', '123456'))
		, (	'0012341098', 'Jemimah Kaye'		, 0, 2, 'Jemimah42',		HASHBYTES('SHA2_512', '123456'))
		, (	'6541231098', 'Kymani Ford'			, 0, 2, 'Kymani78',			HASHBYTES('SHA2_512', '123456'))
		, (	'9384059124', 'Raife Holmes'		, 5, 3, '56Raife',			HASHBYTES('SHA2_512', '123456'))
		, (	'3974835511', 'Rickie Dunne'		, 0, 2, 'Rickie5678',		HASHBYTES('SHA2_512', '123456'))
		, (	'8562430089', 'Honey Spence'		, 0, 2, 'HoneyPooh',		HASHBYTES('SHA2_512', '123456'))
		, (	'1886133339', 'Amanah Weaver'		, 0, 2, 'Amanah31',			HASHBYTES('SHA2_512', '123456'))
		, (	'3032782212', 'Ty Hulme'			, 5, 3, 'Tyhulmee',			HASHBYTES('SHA2_512', '654321'))
		, (	'5131238225', 'Silas Markham'		, 7, 3, 'Silas34',			HASHBYTES('SHA2_512', '654321'))
		, (	'5926849522', 'Raymond Gregory'		, 0, 3, 'RaymondRaymond',	HASHBYTES('SHA2_512', '654321'))
		, (	'7236630925', 'Caitlin Velazquez'	, 0, 3, 'Caitlin3434',		HASHBYTES('SHA2_512', '654321'))
		, (	'6005884841', 'Hisham Wood'			, 2, 3, 'HishamHisham',		HASHBYTES('SHA2_512', '654321'))
		, (	'9592349990', 'Joyce Phelps'		, 0, 2, 'Joyce',			HASHBYTES('SHA2_512', '654321'))
		, (	'4622192123', 'Brax Davenport'		, 0, 2, 'Brax12',			HASHBYTES('SHA2_512', '654321'))
		, (	'2342576356', 'Joann Stacey'		, 0, 2, 'Joann56',			HASHBYTES('SHA2_512', '654321'))
		, (	'4967562458', 'Evan Forster'		, 0, 2, '21Evan',			HASHBYTES('SHA2_512', '654321'))
		, (	'4673783843', 'Riya Jeffery'		, 1, 3, 'Riya88',			HASHBYTES('SHA2_512', '654321'))
		, (	'7356873157', 'Terence Walls'		, 3, 3, 'Terence0',			HASHBYTES('SHA2_512', '654321'))
		, (	'9467835672', 'Pascal Gonzalez'		, 0, 3, 'Pascalgon',		HASHBYTES('SHA2_512', '654321'))
		, (	'2457358632', 'Reuben Walsh'		, 3, 3, 'Reuben312',		HASHBYTES('SHA2_512', '654321'))
END
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'DRIVERS')
BEGIN
	CREATE TABLE DRIVERS
	(
		  ID				INT	IDENTITY(1,1)	NOT NULL			
		, COMPLETED_ORDERS	INT					NOT NULL DEFAULT 0	
		, CUSTOMER_ID		INT					NOT NULL			
		, MONEY_MADE		FLOAT				NOT NULL DEFAULT 0  
		, STATUS			BIT					NOT NULL DEFAULT 0 /* 0 - DriverStatusBusy;  1 - DriverStatusAvailable; */
	)
	
	ALTER TABLE DRIVERS
	ADD CONSTRAINT PK_DRIVERS_ID PRIMARY KEY (ID)

	ALTER TABLE DRIVERS
	ADD FOREIGN KEY (CUSTOMER_ID) REFERENCES CUSTOMERS(ID)

	INSERT INTO DRIVERS
	VALUES
	   ( 3,		1,		15.93 , 1 )	
	 , ( 4,		9,		29.42 , 1 )	
	 , ( 2,		11,		16.22 , 1 )	
	 , ( 4,		12,		23.01 , 1 )	
	 , ( 3,		13,		15.8  , 1 )	
	 , ( 7,		15,		54.53 , 1 )	
	 , ( 3,		16,		20.28 , 1 )	
	 , ( 5,		17,		38.92 , 1 )	
	 , ( 1,		23,		5.5	  , 1 )	
	 , ( 5,		24,		38.49 , 1 )	
	 , ( 1,		25,		6.6	  , 1 )	
	 , ( 1,		26,		8.8	  , 1 )	
END								  						  
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'MANUFACTURERS')
BEGIN
	CREATE TABLE MANUFACTURERS
	(
		ID INT IDENTITY(1, 1)	NOT NULL
		, NAME VARCHAR(60)		NOT NULL
	)
	
	ALTER TABLE MANUFACTURERS
	ADD CONSTRAINT PK_MANUFACTURERS_ID PRIMARY KEY (ID)

	INSERT INTO MANUFACTURERS
	VALUES
	    ('Hyundai')
	  , ('Chevrolet')
	  , ('New Flyer')
	  , ('Honda')
	  , ('Ford')
	  , ('Nissan')
	  , ('Mazda')
END
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'CARS')
BEGIN
	CREATE TABLE CARS
	(
		  KOD_TAXI			INT	IDENTITY(1, 1)	NOT NULL 		   
		, REG_NOMER			VARCHAR(10)			NOT NULL 		   
		, MANUFACTURER_ID	INT					NOT NULL 		   
		, SEATS				TINYINT				NOT NULL DEFAULT 3 
		, LUGGAGE			BIT					NOT NULL DEFAULT 1 
		, DRIVER_ID			INT					NOT NULL DEFAULT 0 
	)
	
	ALTER TABLE CARS
	ADD CONSTRAINT PK_CARS_KOD_TAXI PRIMARY KEY (KOD_TAXI)

	CREATE UNIQUE INDEX UX_CARS_REG_NOMER_MARK
	ON CARS (REG_NOMER, MANUFACTURER_ID)

	ALTER TABLE CARS
	ADD FOREIGN KEY (DRIVER_ID) REFERENCES DRIVERS(ID)

	ALTER TABLE CARS
	ADD FOREIGN KEY (MANUFACTURER_ID) REFERENCES MANUFACTURERS(ID)

	INSERT INTO CARS
	VALUES
	    ('BBZY11',	 1, 3, 1, 12	) --1
	  , ('DCR4198',	 2, 1, 0, 11	) --2
	  , ('1535543',	 3, 7, 0, 9		) --3
	  , ('ECU1368',	 4, 3, 0, 10	) --4
	  , ('ECU4965',	 4, 3, 0, 8		) --5
	  , ('7NLC799',	 4, 1, 1, 7		) --6
	  , ('5LYL388',	 5, 3, 1, 5		) --7
	  , ('AUX3236',	 2, 3, 0, 6		) --8
	  , ('DV39504',	 5, 3, 1, 3		) --9
	  , ('5WAT511',	 6, 3, 1, 4		) --10
	  , ('7TIV425',	 6, 4, 1, 2		) --11
	  , ('SJJ102',	 7, 3, 1, 1		) --12
END										
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'ORDERS')
BEGIN
	CREATE TABLE ORDERS
	(
		  NUM_ORD		INT	IDENTITY(1, 1)	NOT NULL				   
		, KOD_TAXI		INT					NOT NULL				   
		, ADDRESS_FROM	VARCHAR(50)			NOT NULL 				   
		, ADDRESS_TO	VARCHAR(50)			NOT NULL 				   
		, ORD_TIME		DATETIME			NOT NULL DEFAULT GETDATE() 
		, DRIVING_TIME	TIME				
		, DISTANCE		FLOAT				NOT NULL DEFAULT 0		   
		, FARE			FLOAT				NOT NULL DEFAULT 0		   
		, CUSTOMER_ID	INT					NOT NULL				
		, IS_DONE		BIT					NOT NULL DEFAULT 0
	)

	ALTER TABLE ORDERS
	ADD CONSTRAINT PK_CARS_NUM_ORD PRIMARY KEY (NUM_ORD)

	ALTER TABLE ORDERS
	ADD FOREIGN KEY (KOD_TAXI) REFERENCES CARS(KOD_TAXI)

	ALTER TABLE ORDERS
	ADD FOREIGN KEY (CUSTOMER_ID) REFERENCES CUSTOMERS(ID)

	INSERT INTO ORDERS 
	VALUES
	    (12, '37 Peg Shop Ave.',		'Stone Mountain, GA 30083', '2022-05-10 17:12:39.123', '00:05:59',  3,		7.93,	2,	1)
	  , (12, 'Mc Lean, VA 22101',		'Stone Mountain, GA 30083', '2022-04-27 13:20:53.210', '00:02:56',  1.3, 	4,		3,	1)
	  , (12, 'Harlingen, TX 78552',		'60 Adams Dr.',				'2022-01-07 09:10:12.530', '00:02:45',  1.22 , 	4,		4,	1)
	  , (11, '60 Adams Dr.',			'Harlingen, TX 78552',		'2021-10-12 04:11:12.530', '00:04:43',  2.34,	3.56,	8,	1)
	  , (11, '7300 Lawrence Court',		'60 Adams Dr.',				'2022-03-27 09:10:43.530', '00:06:44',  3.4,	6.44,	5,	1)
	  , (11, 'Mc Lean, VA 22101',		'7300 Lawrence Court',		'2022-05-22 09:10:50.930', '00:08:43',  5.94,	9.21,	6,	1)
	  , (11, 'Mc Lean, VA 22101',		'Gaithersburg, MD 20877',	'2022-08-02 02:22:22.120', '00:10:12',  4.39,	10.21,	7,	1)
	  , (10, 'Clifton Park, NY 12065',	'37 Peg Shop Ave.',			'2021-11-12 12:21:33.120', '00:10:09',	9.03,	9.99,	10,	1)
	  , (10, 'Clifton Park, NY 12065',	'Battle Ground, WA 98604',	'2022-06-12 04:32:22.420', '00:02:28',	2.31,	2.02,	14,	1)
	  , (10, '37 Peg Shop Ave.',		'Gaithersburg, MD 20877',	'2021-05-23 18:55:21.156', '00:08:37',	5.3 ,	8.30,	14,	1)
	  , (10, 'Gaithersburg, MD 20877',	'Stone Mountain, GA 30083', '2022-06-18 20:44:31.240', '00:03:02',	3.11,	2.70,	18,	1)
	  , (9,  'Clifton Park, NY 12065',	'Stone Mountain, GA 30083', '2022-08-18 21:34:33.120', '00:02:12',	1.01,	8.11,	6,	1)
	  , (9,  'Osseo, MN 55311',			'81 South Forest Ave.',		'2022-06-28 11:54:51.222', '00:05:49',	4.19,	8.11,	5,	1)
	  , (8,  'Mc Lean, VA 22101',		'Stone Mountain, GA 30083', '2022-06-28 11:54:51.251', '00:05:18',	4.1,	5.99,	6,	1)
	  , (8,  'Clifton Park, NY 12065',	'81 South Forest Ave.',		'2022-07-18 12:54:51.244', '00:08:49',	7.09,	8.23,	8,	1)
	  , (8,  '37 Peg Shop Ave.',		'60 Adams Dr.',				'2022-06-24 13:54:51.882', '00:03:44',	4.23,	7.89,	10,	1)
	  , (8,  'Osseo, MN 55311',			'8155 West St.',			'2022-04-25 04:54:51.282', '00:04:29',	3.98,	3.65,	14,	1)
	  , (8,  '8155 West St.',			'523 Heritage Ave.',		'2022-02-06 19:54:51.218', '00:02:18',	2.67,	10.34,	14,	1)
	  , (8,  '60 Adams Dr.',			'Phillipsburg, NJ 08865',	'2022-03-09 17:54:51.182', '00:06:32',	4.79,	14.23,	14,	1)
	  , (8,  'Phillipsburg, NJ 08865',	'523 Heritage Ave.',		'2022-06-28 18:18:18.180', '00:05:49',	4.91,	4.20,	18,	1)
	  , (7,  'Battle Ground, WA 98604', '81 South Forest Ave.',		'2022-02-18 18:18:14.000', '00:03:41',	3.21,	3.21,	19, 1)
	  , (7,  'Battle Ground, WA 98604', '37 Peg Shop Ave.',			'2022-03-05 19:12:32.080', '00:08:23',	9.32,	9.10,	18, 1)
	  , (7,  '60 Adams Dr.',			'523 Heritage Ave.',		'2022-04-04 22:28:23.021', '00:05:22',	4.27,	3.49,	18, 1)
	  , (6,  '37 Peg Shop Ave.',		'7300 Lawrence Court',		'2021-10-24 16:54:21.024', '00:04:33',	5.65,	12.1,	22, 1)
	  , (6,  '13 Boston Circle',		'7300 Lawrence Court',		'2022-09-24 23:41:09.094', '00:06:11',	3.84,	3.26,	19, 1)
	  , (6,  '60 Adams Dr.',			'7300 Lawrence Court',		'2022-07-10 21:23:07.018', '00:07:29',	6.53,	4.92,	19, 1)
	  , (5,  '60 Adams Dr.',			'Battle Ground, WA 98604',	'2022-08-21 21:43:02.032', '00:06:21',	5.23,	5.99,	22, 1)
	  , (5,  '7300 Lawrence Court',		'Harlingen, TX 78552',		'2022-04-20 18:23:27.548', '00:11:33',	12.34,	20.31,	19, 1)
	  , (5,  '7300 Lawrence Court',		'Phillipsburg, NJ 08865',	'2022-05-12 14:43:57.113', '00:02:45',	1.56,	3.12,	30, 1)
	  , (5,  '7300 Lawrence Court',		'Harlingen, TX 78552',		'2022-02-14 13:03:36.048', '00:03:22',	3.4,	3.4,	30, 1)
	  , (5,  '81 South Forest Ave.',	'Stone Mountain, GA 30083', '2022-08-18 08:02:47.512', '00:04:23',	5.2,	6.10,	19, 1)
	  , (4,  'Clifton Park, NY 12065',	'Phillipsburg, NJ 08865',	'2022-08-01 12:02:41.222', '00:01:45',	2,		4,		28, 1)
	  , (4,  'Harlingen, TX 78552',		'13 Boston Circle',			'2022-08-01 13:51:37.312', '00:05:27',	6.03,	10.67,	30, 1)
	  , (4,  '8155 West St.',			'Battle Ground, WA 98604',	'2022-08-01 14:22:57.012', '00:05:58',	6.3,	7.59,	27, 1)
	  , (4,  'Clifton Park, NY 12065',	'Harlingen, TX 78552',		'2022-08-02 14:21:12.000', '00:06:46',	7.9,	9.89,	19, 1)
	  , (4,  '13 Boston Circle',		'Stone Mountain, GA 30083', '2022-08-01 14:51:34.002', '00:04:49',	3.99,	6.34,	18, 1)
	  , (3,  'Phillipsburg, NJ 08865',	'523 Heritage Ave.',		'2022-04-11 23:51:47.041', '00:06:25',	7.77,	5.5,	18, 1)
	  , (2,  'Harlingen, TX 78552',		'523 Heritage Ave.',		'2022-05-14 15:15:21.501', '00:04:25',	3.02,	6.6,	28, 1)
	  , (1,  '81 South Forest Ave.',	'523 Heritage Ave.',		'2022-03-22 22:55:37.003', '00:08:10',	9.82,	8.8,	28, 1)
END
GO

IF NOT EXISTS (SELECT * FROM sys.tables WITH(NOLOCK) WHERE NAME = 'ORDER_REQUESTS')
BEGIN
	CREATE TABLE ORDER_REQUESTS
	(
		  ID			INT IDENTITY(1, 1)	NOT NULL
		, CUSTOMER_ID	INT					NOT NULL
		, ADDRESS_FROM	VARCHAR(50)			NOT NULL 		
		, ADDRESS_TO	VARCHAR(50)			NOT NULL 		
		, ORD_TIME		DATETIME			NOT NULL DEFAULT GETDATE()
	)

	ALTER TABLE ORDER_REQUESTS
	ADD CONSTRAINT PK_ORDER_REQUESTS_ID PRIMARY KEY (ID)

	ALTER TABLE ORDER_REQUESTS
	ADD FOREIGN KEY (CUSTOMER_ID) REFERENCES CUSTOMERS(ID)
END
GO

IF EXISTS (SELECT * FROM sys.procedures WITH(NOLOCK) WHERE NAME = 'LOGIN_AUTHENTICATION')
BEGIN
	DROP PROCEDURE LOGIN_AUTHENTICATION
END
GO
	
CREATE PROCEDURE LOGIN_AUTHENTICATION 
	@USERNAME VARCHAR(60), 
	@PASSWORD VARCHAR(64),
	@RESULT INT = 0 OUTPUT
AS
BEGIN
	SET @RESULT = 0
	DECLARE @HASH_PASS_INPUT BINARY(64) = HASHBYTES('SHA2_512', @PASSWORD)

	IF EXISTS (SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = @USERNAME AND PASSWORD = @HASH_PASS_INPUT)
	BEGIN
		SET @RESULT = 1
	END
	
	SELECT @RESULT AS RESULT
END
GO

IF EXISTS (SELECT * FROM sys.procedures WITH(NOLOCK) WHERE NAME = 'CHECK_USERNAME_AVAILABILITY')
BEGIN
	DROP PROCEDURE CHECK_USERNAME_AVAILABILITY
END
GO
	
CREATE PROCEDURE CHECK_USERNAME_AVAILABILITY 
	@USERNAME VARCHAR(60), 
	@RESULT INT = 1 OUTPUT
AS
BEGIN	
	SET @RESULT = 1

	IF EXISTS (SELECT * FROM CUSTOMERS WITH(NOLOCK) WHERE USERNAME = @USERNAME)
	BEGIN
		SET @RESULT = 0
	END
	
	SELECT @RESULT AS RESULT
END
GO
