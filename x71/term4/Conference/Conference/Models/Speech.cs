using System;
using System.ComponentModel.DataAnnotations;
using System.Data.Entity;

namespace Conference.Models
{
    public class Speech
    {
        public int Id { get; set; }
        public string Title { get; set; }
        public string UserId { get; set; }

        public int Vote { get; set; }

        [DataType(DataType.MultilineText)]
        public string Thesises { get; set; }
    }

    public class SpeechDBContext : DbContext
    {
        public DbSet<Speech> Speeches { get; set; }
    }
}