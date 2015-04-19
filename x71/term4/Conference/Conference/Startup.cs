using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Conference.Startup))]
namespace Conference
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
