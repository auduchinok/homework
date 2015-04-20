using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Conference.Models;
using Microsoft.AspNet.Identity;

namespace Conference.Controllers
{
    [Authorize]
    public class SpeechesController : Controller
    {
        private SpeechDBContext db = new SpeechDBContext();

        public ActionResult My()
        {
            var userId = User.Identity.GetUserId();
            var speeches = from s in db.Speeches select s;
            speeches = speeches.Where(s => s.UserId == userId);

            return View(speeches);
        }

        // GET: Speeches
        [AllowAnonymous]
        public ActionResult Index()
        {
            return View(db.Speeches.ToList());
        }

        // GET: Speeches/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Speech speech = db.Speeches.Find(id);
            if (speech == null)
            {
                return HttpNotFound();
            }
            return View(speech);
        }

        // GET: Speeches/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Speeches/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "Id,Title,Thesises")] Speech speech)
        {
            if (ModelState.IsValid)
            {
                speech.UserId = User.Identity.GetUserId();
                db.Speeches.Add(speech);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(speech);
        }

        // GET: Speeches/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Speech speech = db.Speeches.Find(id);
            if (speech == null)
            {
                return HttpNotFound();
            }
            return View(speech);
        }

        // POST: Speeches/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,Title,Thesises")] Speech speech)
        {
            if (ModelState.IsValid)
            {
                db.Entry(speech).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(speech);
        }

        // GET: Speeches/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Speech speech = db.Speeches.Find(id);
            if (speech == null)
            {
                return HttpNotFound();
            }
            return View(speech);
        }

        // POST: Speeches/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Speech speech = db.Speeches.Find(id);
            db.Speeches.Remove(speech);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
