SELECT title FROM movies
JOIN ratings on movies.id = ratings.movie_id
JOIN stars on ratings.movie_id = stars.movie_id
JOIN people on stars.person_id = people.id
WHERE people.id = (SELECT id FROM people WHERE name = "Chadwick Boseman")
ORDER BY rating DESC
LIMIT 5;