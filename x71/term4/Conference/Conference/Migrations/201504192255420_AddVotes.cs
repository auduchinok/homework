namespace Conference.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddVotes : DbMigration
    {
        public override void Up()
        {
            AddColumn("dbo.Speeches", "Vote", c => c.Int(nullable: false));
        }
        
        public override void Down()
        {
            DropColumn("dbo.Speeches", "Vote");
        }
    }
}
