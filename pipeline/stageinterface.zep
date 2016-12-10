namespace Pipeline;

/**
 * The stage interface.
 */
interface StageInterface
{
	/**
	 * @param  mixed playload
	 * @return mixed
	 */
	public function __invoke(var payload);
}