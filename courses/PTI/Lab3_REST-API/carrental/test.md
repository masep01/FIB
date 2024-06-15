# How to test

## New rental
Test it with `curl`
```bash
curl -X POST -H "Content-Type: application/json" -d '{"maker":"test0", "model":"test2", "days":"1", "units":"2"}' http://localhost:8080/newrental
```
## List
```bash
curl -H "Content-Type: application/json"  http://localhost:8080/list
```
