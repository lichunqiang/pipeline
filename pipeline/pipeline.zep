namespace Pipeline;

class Pipeline implements PipelineInterface
{
	/**
	 * @var array stages Process stages.
	 */
	private stages = [];
	/**
	 * @var ProcessorInterface processor
	 */
	private processor;

	public function __construct(array! stages = [], <ProcessorInterface> processor = null)
	{
		var stage;
		for stage in stages {
			if (false === is_callable(stage)) {
				throw new \InvalidArgumentException("All stages should be callable.");
			}
		}

		let this->stages = stages;
		let this->processor = processor ? processor : new DefaultProcessor();
	}

	public function pipe(var opertaion) -> <PipelineInterface>
	{
		let this->stages[] = opertaion;

		return this;
	}

	/**
	 * @param  mixed playload
	 * @return mixed
	 */
	public function process(var playload)
	{
		return this->processor->process(this->stages, playload);
	}

	/**
	 * @param  mixed playload
	 * @return mixed
	 */
	public function __invoke(var playload)
	{
		return this->process(playload);
	}

	public function getStages() -> array
	{
		return this->stages;
	}

	public function getProcessor() -> <ProcessorInterface>
	{
		return this->processor;
	}
}