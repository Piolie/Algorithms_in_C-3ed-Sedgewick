BIG O NOTATION NOTES
--------------------

I think the book doesn't do a very good job at defining and explaining this notation. All we have is:

>**Definition 2.1**  A function g(N) is said to be O(f(N)) if there exist constants c<sub>0</sub> and N<sub>0</sub> such that g(N) < c<sub>0</sub> f(N), for all N > N<sub>0</sub>.

This is all nice and good, but there is no definition of what kO(f(N)) or the sum O(f(N)) + O(g(N)) mean, for example. It's one thing to say that a "function _is_ O(f(N))", it's quite another to write "g(N) = O(f(N))" and replace it in equations and inequalities, at least with no additional definitions or justifications.

The matter is much better explained in the book _Introduction to Algorithms_, Third Edition, by Cormen, et al (3.1 Asymptotic notation):

>For a given function g(n), we denote by O(g(n)) (pronounced "big-oh of g of n" or sometimes just "oh of g of n") the set of functions

>O(g(n)) = {f(n) : there exist positive constants c and n<sub>0</sub> such that 0 < f(n) < cg(n) for all n > n<sub>0</sub>}.

>We use O-notation to give an upper bound on a function, to within a constant factor. For all values n at and to the right of n<sub>0</sub>, the value of the function f(n) is on or below cg(n).

>We write f(n) = O(g(n)) to indicate that a function f(n) _is a member of the set O(g(n))_.

>If you have seen O-notation before, you might find it strange that we should write, for example, n = O(n<sup>2</sup>). (...) In this book, however, when we write f(n) = O(g(n)), we are merely claiming that some constant multiple of g(n) is an asymptotic upper bound on f(n), with no claim about how tight an upper bound it is. Distinguishing asymptotic upper bounds from asymptotically tight bounds is standard in the algorithms literature.

>**Asymptotic notation in equations and inequalities**:

>We have already seen how asymptotic notation can be used within mathematical formulas. For example, in introducing O-notation, we wrote "n<sup>2</sup> = O(n<sup>2</sup>)". We might also write 2n<sup>2</sup> + 3n + 1 = 2n<sup>2</sup> + O(n). How do we interpret such formulas?

>When the asymptotic notation stands alone (that is, not within a larger formula) on the right-hand side of an equation (or inequality), as in n = O(n<sup>2</sup>), we have already defined the equal sign to mean set membership: n ∈ O(n<sup>2</sup>). In general, however, when asymptotic notation appears in a formula, we interpret it as standing for some anonymous function that we do not care to name. For example, the formula 2n<sup>2</sup> + 3n + 1 = 2n<sup>2</sup> + O(n) means that 2n<sup>2</sup> + 3n + 1 = 2n<sup>2</sup> + f(n), where f(n) is some function in the set O(n). In this case, we let f(n) = 3n + 1, which indeed is in O(n).

>Using asymptotic notation in this manner can help eliminate inessential detail and clutter in an equation.

>In some cases, asymptotic notation appears on the left-hand side of an equation, as in

><code>2n<sup>2</sup> + O(n) = O(n<sup>2</sup>).</code>

>We interpret such equations using the following rule: No matter how the anonymous functions are chosen on the left of the equal sign, there is a way to choose the anonymous functions on the right of the equal sign to make the equation valid. Thus, our example means that for any function f(n) ∈ O(n), there is some function g(n) ∈ O(n<sup>2</sup>) such that 2n<sup>2</sup> + f(n) = g(n) for all n. In other words, the right-hand side of an equation provides a coarser level of detail than the left-hand side.

>We can chain together a number of such relationships, as in <code>2n<sup>2</sup> + 3n + 1 = 2n<sup>2</sup> + O(n) = O(n<sup>2</sup>).</code>

>We can interpret each equation separately by the rules above. The first equation says that there is some function f(n) ∈ O(n) such that 2n<sup>2</sup> + 3n + 1 = 2n<sup>2</sup> + f(n) for all n. The second equation says that for any function g(n) ∈ O(n) (such as the f(n) just mentioned), there is some function h(n) ∈ O(n^2) such that 2n<sup>2</sup> + g(n) = h(n) for all n. Note that this interpretation implies that 2n<sup>2</sup> + 3n + 1 = O(n<sup>2</sup>), which is what the chaining of equations intuitively gives us.

Another fine reference is _Concrete Mathematics: A Foundation for Computer Science_, Second Edition, Graham and Knuth (9.2 O NOTATION and 9.3 O MANIPULATION).
