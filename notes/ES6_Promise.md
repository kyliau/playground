If an exception is thrown within the passed-in function, the promise will automatically be marked as rejected, with the exception object being stored as the rejected value, just as if it had been passed as the argument to reject.

Rejection handlers in `promise.then` return resolved promises, not rejected ones.

`Promise.then` turns exceptions into rejected promises.

`promise.catch(handler)` is equivalent to `promise.then(null, handler)`.
