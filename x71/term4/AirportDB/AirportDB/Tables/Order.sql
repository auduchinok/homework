CREATE TABLE [dbo].[Order]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [CustomerId] INT NULL, 
    [CreatedAt] DATETIME2 NULL, 
    [FlightId] INT NULL, 
    [Seats] INT NULL, 
    [Price] DECIMAL(18, 2) NULL, 
    CONSTRAINT [FK_Order_Flight] FOREIGN KEY ([FlightId]) REFERENCES [Flight]([Id]), 
    CONSTRAINT [FK_Order_Customer] FOREIGN KEY ([CustomerId]) REFERENCES [Customer]([Id])
)
