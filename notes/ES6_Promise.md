1. If an exception is thrown within the passed-in function, the promise will automatically be marked as rejected, with the exception object being stored as the rejected value, just as if it had been passed as the argument to reject.
2. Rejection handlers in `promise.then` return resolved promises, not rejected ones.
3. `Promise.then` turns exceptions into rejected promises.
4. `promise.catch(handler)` is equivalent to `promise.then(null, handler)`.
5. Any exception which is thrown within a `then` handler, a `catch` handler, or within the function passed to `new Promise`, will be silently disposed of unless manually handled.
